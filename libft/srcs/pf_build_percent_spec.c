/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_%_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:36:58 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:12:50 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector			*pf_build_percent_spec(t_flags *flags, va_list ap)
{
	t_vector			*app;
	char				filler;

	(void)(ap);
	if ((flags->mask & ISZERO) != 0 && (flags->mask & ISMINUS) == 0)
		filler = '0';
	else
		filler = ' ';
	app = vct_new(VCT_DEFSIZE);
	vct_app_char(app, '%');
	if (flags->widval != PF_FLAGS_DEFAULT)
	{
		if (flags->mask & ISMINUS)
			vct_insert_nchar(app, app->len, filler, flags->widval - 1);
		else
			vct_insert_nchar(app, 0, filler, flags->widval - 1);
	}
	return (app);
}
