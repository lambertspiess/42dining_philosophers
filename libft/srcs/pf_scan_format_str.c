/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_scan_format_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:06:15 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:13:33 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	DESCRIPTION
** Checks if a valid conversion substring follows the '%' flag.
** If not, appends the substring to the vector.
*/

static int		pf_scan_is_validconv(t_pf_fmt *fmt)
{
	int				j;

	j = fmt->idx + 1;
	while (fmt->s[j] && !(ft_strchr(CONV_SPEC, fmt->s[j])))
		j++;
	if (fmt->s[j] == '\0')
	{
		fmt->idx = fmt->idx;
		return (FALSE);
	}
	else
		return (TRUE);
}

t_stroke		pf_scan_format_str(t_pf_fmt *fmt, t_vector *vct,
								t_flags *flags, va_list ap)
{
	t_stroke		stroke;

	UNUSED(ap);
	UNUSED(flags);
	stroke.curstate = SCANNING_FORMAT_STR;
	while ((size_t)(fmt->idx) < fmt->len)
	{
		if (fmt->s[fmt->idx] != '%')
			vct_app_char(vct, fmt->s[fmt->idx]);
		else if (fmt->s[fmt->idx] == '%')
		{
			if (pf_scan_is_validconv(fmt) == TRUE)
			{
				stroke.lastevent = METCONV;
				return (stroke);
			}
		}
		fmt->idx++;
	}
	stroke.lastevent = EXIT;
	return (stroke);
}
