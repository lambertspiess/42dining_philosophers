/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_x_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:06:35 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:14:31 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_build_x_spec_width(t_vector *app, t_flags *flags, \
											int isargnull)
{
	int					i;

	i = 0;
	if ((flags->mask & ISOCT) && (flags->mask & ISZERO) && !isargnull)
		while (app->str[i] != 'x' && app->str[i] != 'X')
			i++;
	if (flags->widval > (int)(app->len))
	{
		if (flags->mask & ISMINUS)
			vct_insert_nchar(app, app->len, ' ', flags->widval - app->len);
		else if ((flags->mask & ISZERO) && ((flags->mask & ISDOT) == 0))
		{
			vct_insert_nchar(app, i > 0 ? i + 1 : 0, '0', \
								flags->widval - app->len);
		}
		else
			vct_insert_nchar(app, 0, ' ', flags->widval - app->len);
	}
}

static t_vector		*pf_build_nomod_x_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	unsigned int		arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, unsigned int);
	arg_str = ft_utoa_base(arg, 16);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISMAJ) != 0)
		ft_strcapitalize(app->str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	if ((arg != 0) && ((flags->mask & ISOCT) != 0))
	{
		if ((flags->mask & ISMAJ) != 0)
			vct_insert_str(app, 0, "0X");
		else
			vct_insert_str(app, 0, "0x");
	}
	pf_build_x_spec_width(app, flags, arg == 0 ? 1 : 0);
	return (app);
}

static t_vector		*pf_build_lmod_x_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	unsigned long		arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, unsigned long);
	arg_str = ft_ultoa_base(arg, 16);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISMAJ) != 0)
		ft_strcapitalize(app->str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	if ((arg != 0) && ((flags->mask & ISOCT) != 0))
	{
		if ((flags->mask & ISMAJ) != 0)
			vct_insert_str(app, 0, "0X");
		else
			vct_insert_str(app, 0, "0x");
	}
	pf_build_x_spec_width(app, flags, arg == 0 ? 1 : 0);
	return (app);
}

static t_vector		*pf_build_llmod_x_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	unsigned long long	arg;
	char				*arg_str;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, unsigned long long);
	arg_str = ft_ulltoa_base(arg, 16);
	vct_app_str(app, arg_str);
	if ((flags->mask & ISMAJ) != 0)
		ft_strcapitalize(app->str);
	if ((flags->mask & ISDOT) != 0)
		pf_build_num_spec_precision(app, flags, arg_str);
	free(arg_str);
	if ((arg != 0) && ((flags->mask & ISOCT) != 0))
	{
		if ((flags->mask & ISMAJ) != 0)
			vct_insert_str(app, 0, "0X");
		else
			vct_insert_str(app, 0, "0x");
	}
	pf_build_x_spec_width(app, flags, arg == 0 ? 1 : 0);
	return (app);
}

t_vector			*pf_build_x_spec(t_flags *flags, va_list ap)
{
	if ((flags->mask & ISLONG) != 0)
		return (pf_build_lmod_x_spec(flags, ap));
	else if ((flags->mask & ISLONGLONG) != 0)
		return (pf_build_llmod_x_spec(flags, ap));
	else
		return (pf_build_nomod_x_spec(flags, ap));
}
