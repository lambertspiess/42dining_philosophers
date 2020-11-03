/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_s_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:00:55 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/14 15:03:51 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*pf_build_s_spec(t_flags *flags, va_list ap)
{
	t_vector		*app;
	char			*arg;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, char *);
	if (arg != NULL)
		vct_app_str(app, arg);
	else
		vct_app_str(app, "(null)");
	if (flags->mask & ISDOT)
	{
		if (flags->precval == PF_FLAGS_DEFAULT)
			flags->precval = 0;
		if ((int)(app->len) > flags->precval)
			vct_cutfrom(app, flags->precval);
	}
	if (flags->widval != PF_FLAGS_DEFAULT && (int)(app->len) < flags->widval)
	{
		if (flags->mask & ISMINUS)
			vct_insert_nchar(app, app->len, ' ', flags->widval - app->len);
		else
			vct_insert_nchar(app, 0, ' ', flags->widval - app->len);
	}
	return (app);
}
