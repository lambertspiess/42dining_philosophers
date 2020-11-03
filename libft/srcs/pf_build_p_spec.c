/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_p_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:02:48 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:03:13 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*pf_build_p_spec(t_flags *flags, va_list ap)
{
	unsigned long long	arg;
	t_vector			*app;
	char				*hex_conv_str;
	int					wid_dif;

	arg = va_arg(ap, long long unsigned);
	app = vct_new(VCT_DEFSIZE);
	vct_app_str(app, (hex_conv_str = ft_ulltoa_base(arg, 16)));
	free(hex_conv_str);
	vct_insert_str(app, 0, "0x");
	if (flags->widval != PF_FLAGS_DEFAULT)
	{
		if ((int)(app->len) < flags->widval)
		{
			wid_dif = flags->widval - (int)(app->len);
			if (flags->mask & ISMINUS)
				vct_insert_nchar(app, app->len, ' ', wid_dif);
			else
				vct_insert_nchar(app, 0, ' ', wid_dif);
		}
	}
	return (app);
}
