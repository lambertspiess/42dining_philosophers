/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_argstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:28:53 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 19:39:42 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TABSTOP	-1

static t_pf_spec_handler	g_spectab[] = {
	{'%', &pf_build_percent_spec},
	{'c', &pf_build_c_spec},
	{'s', &pf_build_s_spec},
	{'p', &pf_build_p_spec},
	{'d', &pf_build_d_spec},
	{'i', &pf_build_d_spec},
	{'u', &pf_build_u_spec},
	{'x', &pf_build_x_spec},
	{'X', &pf_build_x_spec},
	{TABSTOP, NULL},
};

t_stroke	pf_build_argstr(t_pf_fmt *fmt, t_vector *vct,
								t_flags *flags, va_list ap)
{
	int			i;
	t_vector	*app;
	t_stroke	stroke;

	stroke.curstate = BUILDING_ARGSTR;
	i = 0;
	while (g_spectab[i].spec != fmt->s[fmt->idx] \
			&& g_spectab[i].spec != TABSTOP)
		i++;
	if (g_spectab[i].spec == TABSTOP)
	{
		stroke.lastevent = EXIT;
		return (stroke);
	}
	app = g_spectab[i].pf_build_spec(flags, ap);
	vct_insert_nvct(vct, vct->len, app, app->len);
	vct_free(&app);
	stroke.lastevent = ARGSTR_BUILT;
	fmt->idx++;
	return (stroke);
}

/*
**t_stroke	pf_build_argstr(t_pf_fmt *fmt, t_vector *vct,
**								t_flags *flags, va_list ap)
**{
**	int			i;
**	t_vector	*app;
**	t_stroke	stroke;
**
**	stroke.curstate = BUILDING_ARGSTR;
**	i = 0;
**	while (spectab[i].spec != fmt->s[fmt->idx] && spectab[i].spec != TABSTOP)
**		i++;
**	if (spectab[i].spec == TABSTOP)
**	{
**		stroke.lastevent = EXIT;
**		return (stroke);
**	}
**	app = spectab[i].pf_build_spec(flags, ap);
**	vct_insert_nvct(vct, vct->len, app, app->len);
**	vct_free(&app);
**	stroke.lastevent = ARGSTR_BUILT;
**	fmt->idx++;
**	return (stroke);
**}
*/
