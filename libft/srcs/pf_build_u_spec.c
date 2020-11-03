/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_u_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:04:44 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:05:01 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_vector		*pf_build_nomod_u_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	unsigned int		arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, unsigned int);
	arg_str = ft_utoa(arg);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	pf_build_num_spec_width(app, flags);
	return (app);
}

static t_vector		*pf_build_lmod_u_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	unsigned long		arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, unsigned long);
	arg_str = ft_ultoa(arg);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	pf_build_num_spec_width(app, flags);
	return (app);
}

static t_vector		*pf_build_llmod_u_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	unsigned long long	arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, unsigned long long);
	arg_str = ft_ulltoa(arg);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	pf_build_num_spec_width(app, flags);
	return (app);
}

t_vector			*pf_build_u_spec(t_flags *flags, va_list ap)
{
	if ((flags->mask & ISLONG) != 0)
		return (pf_build_lmod_u_spec(flags, ap));
	else if ((flags->mask & ISLONGLONG) != 0)
		return (pf_build_llmod_u_spec(flags, ap));
	else
		return (pf_build_nomod_u_spec(flags, ap));
}
