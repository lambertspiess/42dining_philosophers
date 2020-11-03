/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_c_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:26:02 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/09 15:08:02 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector			*pf_build_c_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	char				arg;

	app = vct_new(VCT_DEFSIZE);
	arg = va_arg(ap, int);
	vct_app_char(app, arg);
	if (flags->widval != PF_FLAGS_DEFAULT)
	{
		if (flags->mask & ISMINUS)
			vct_insert_nchar(app, app->len, ' ', flags->widval - 1);
		else
			vct_insert_nchar(app, 0, ' ', flags->widval - 1);
	}
	return (app);
}
