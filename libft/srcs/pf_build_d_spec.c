/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_d_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:03:20 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:04:20 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag '0' ignored when '-' is present
** flag ' ' ignored when '+' is present
** ' ' : if the conversion is signed, a blank precedes the positive number.
** '+' : if the conversion is signed, a sign precedes the number
** precision : if bigger than arglen, pad zeroes the left of the value with
** zeroes..
*/

static t_vector		*pf_build_nomod_d_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	int					arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, int);
	arg_str = ft_itoa(arg);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	if (arg >= 0)
	{
		if (flags->mask & ISPLUS)
			vct_insert_nchar(app, 0, '+', 1);
		else if (flags->mask & ISSPACE)
			vct_insert_nchar(app, 0, ' ', 1);
	}
	pf_build_num_spec_width(app, flags);
	return (app);
}

static t_vector		*pf_build_lmod_d_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	long				arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, long);
	arg_str = ft_ltoa(arg);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	if (arg >= 0)
	{
		if (flags->mask & ISPLUS)
			vct_insert_nchar(app, 0, '+', 1);
		else if (flags->mask & ISSPACE)
			vct_insert_nchar(app, 0, ' ', 1);
	}
	pf_build_num_spec_width(app, flags);
	return (app);
}

static t_vector		*pf_build_llmod_d_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	long long			arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, long long);
	arg_str = ft_lltoa(arg);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	if (arg >= 0)
	{
		if (flags->mask & ISPLUS)
			vct_insert_nchar(app, 0, '+', 1);
		else if (flags->mask & ISSPACE)
			vct_insert_nchar(app, 0, ' ', 1);
	}
	pf_build_num_spec_width(app, flags);
	return (app);
}

t_vector			*pf_build_d_spec(t_flags *flags, va_list ap)
{
	if (flags->mask & ISLONG)
		return (pf_build_lmod_d_spec(flags, ap));
	else if (flags->mask & ISLONGLONG)
		return (pf_build_llmod_d_spec(flags, ap));
	else
		return (pf_build_nomod_d_spec(flags, ap));
}
