/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_asvct_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:26:34 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 18:56:42 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_pfengine	g_engine[] = {
	{RESTING, START, &pf_scan_format_str},
	{SCANNING_FORMAT_STR, METCONV, &pf_parse_conv_substr},
	{PARSING_CONV_SUBSTR, CONV_PARSED, &pf_build_argstr},
	{BUILDING_ARGSTR, ARGSTR_BUILT, &pf_scan_format_str},
	{END, ANY, NULL}
};

t_vector			*pf_asvct_printf(const char *restrict format, va_list ap)
{
	t_vector			*vct;
	t_pf_fmt			fmt;
	t_stroke			stroke;
	int					i;
	t_flags				flags;

	fmt.s = (char *)format;
	fmt.idx = 0;
	fmt.len = ft_strlen(fmt.s);
	vct = vct_new(VCT_DEFSIZE);
	stroke.curstate = RESTING;
	stroke.lastevent = START;
	while (stroke.lastevent != EXIT)
	{
		i = 0;
		while (g_engine[i].state != stroke.curstate \
				&& g_engine[i].state != END \
				&& (g_engine[i].event != stroke.lastevent))
			i++;
		if (g_engine[i].state == END)
			break ;
		stroke = g_engine[i].pf_run(&fmt, vct, &flags, ap);
	}
	return (vct);
}

/*
**t_vector			*pf_asvct_printf(const char * restrict format, va_list ap)
**{
**	t_vector			*vct;
**	t_pf_fmt			fmt;
**	t_stroke			stroke;
**	int					i;
**	t_flags				flags;
**
**	fmt.s = (char *)format;
**	fmt.idx = 0;
**	fmt.len = ft_strlen(fmt.s);
**	vct = vct_new(VCT_DEFSIZE);
**	stroke.curstate = RESTING;
**	stroke.lastevent = START;
**	while (stroke.lastevent != EXIT)
**	{
**		i = 0;
**		printf("New loop, i = %d, engine[%d] = %d, %d, stroke = %d, %d\n",
**	i, i, engine[i].state, engine[i].event, stroke.curstate, stroke.lastevent);
**		while (engine[i].state != stroke.curstate && engine[i].state != END \
**			&& (engine[i].event != stroke.lastevent))
**		{
**			printf("\tloop i = %d, engine[%d] = %d %d\n",
**				i, i, engine[i].state, engine[i].event);
**			i++;
**		}
**		printf("stopped on i = %d, engine[%d] = %d, %d\n\n",
**			i, i, engine[i].state, engine[i].event);
**		if (engine[i].state == END)
**			break ;
**		stroke = engine[i].pf_run(&fmt, vct, &flags, ap);
**		printf("back in engine, fmt->idx = %d, fmt->s[%d] = %c\n",
**				fmt.idx, fmt.idx, fmt.s[fmt.idx]);
**		printf("end of loop, stroke curstate = %d, stroke lastevent = %d\n\n",
**		stroke.curstate, stroke.lastevent);
**	}
**	return (vct);
**}
*/
