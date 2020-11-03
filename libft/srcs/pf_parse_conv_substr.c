/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_conv_substr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:07:39 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:08:25 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_parse_reset_flags(t_flags *flags)
{
	flags->widval = PF_FLAGS_DEFAULT;
	flags->precval = PF_FLAGS_DEFAULT;
	flags->mask = 0;
}

static void		pf_parse_record_flag(t_flags *flags, char c)
{
	if (c == '-')
		flags->mask = (flags->mask | ISMINUS);
	else if (c == '+')
		flags->mask = (flags->mask | ISPLUS);
	else if (c == ' ')
		flags->mask = (flags->mask | ISSPACE);
	else if (c == '0')
		flags->mask = (flags->mask | ISZERO);
	else if (c == '.')
		flags->mask = (flags->mask | ISDOT);
	else if (c == '*')
		flags->mask = (flags->mask | ISWILD);
	else if (c == '#')
		flags->mask = (flags->mask | ISOCT);
}

/*
**static void		pf_print_flags(t_flags *flags)
**{
**	printf("flags->widval = %d, flags->precval = %d, flags->mask = %u\n",
**			flags->widval, flags->precval, flags->mask);
**}
*/

static int		pf_parse_width_prec(t_pf_fmt *fmt, int i, t_flags *flags,
										va_list ap)
{
	while (fmt->s[i] && fmt->s[i] != 'l' && !(ft_strchr(CONV_SPEC, fmt->s[i])))
	{
		pf_parse_record_flag(flags, fmt->s[i]);
		if (fmt->s[i] == '*')
		{
			if (flags->mask & ISDOT)
				flags->precval = va_arg(ap, int);
			else
				flags->widval = va_arg(ap, int);
			i++;
		}
		else if (ft_isdigit(fmt->s[i]))
		{
			if (flags->mask & ISDOT)
				flags->precval = ft_atoi(&(fmt->s[i]));
			else
				flags->widval = ft_atoi(&(fmt->s[i]));
			while (ft_isdigit(fmt->s[i]))
				i++;
		}
		else
			i++;
	}
	return (i);
}

static int		pf_parse_size_modifiers(t_pf_fmt *fmt, int i, t_flags *flags)
{
	int				lflags;

	lflags = 0;
	while (fmt->s[i] && !ft_strchr(CONV_SPEC, fmt->s[i]))
	{
		if (fmt->s[i] == 'l')
			lflags++;
		i++;
	}
	if (lflags == 1)
		flags->mask = (flags->mask | ISLONG);
	else if (lflags > 1)
		flags->mask = (flags->mask | ISLONGLONG);
	return (i);
}

t_stroke		pf_parse_conv_substr(t_pf_fmt *fmt, t_vector *vct,
											t_flags *flags, va_list ap)
{
	t_stroke		stroke;
	int				i;

	UNUSED(vct);
	stroke.curstate = PARSING_CONV_SUBSTR;
	pf_parse_reset_flags(flags);
	i = fmt->idx + 1;
	while (fmt->s[i] && !ft_strchr(CONV_SPEC, fmt->s[i]) && fmt->s[i] != '*' \
			&& fmt->s[i] != '.' && (fmt->s[i] < '1' || fmt->s[i] > '9') \
			&& (fmt->s[i] != 'l'))
	{
		pf_parse_record_flag(flags, fmt->s[i]);
		i++;
	}
	i = pf_parse_width_prec(fmt, i, flags, ap);
	i = pf_parse_size_modifiers(fmt, i, flags);
	fmt->idx = i;
	if (fmt->s[fmt->idx] == 'X')
		flags->mask = (flags->mask | ISMAJ);
	stroke.lastevent = CONV_PARSED;
	return (stroke);
}
