/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_num_spec_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:24:03 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/14 18:22:08 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Nota : the behavior of numeric specs when a precision of zero is specified
** (explicitely or by a mean of a single dot) is to display the value of the
** number if it is non-zero, and to display nothing if it is equal to zero.
*/

void				pf_build_num_spec_precision(t_vector *app, t_flags *flags,
													char *arg_str)
{
	if ((flags->mask & ISDOT) != 0)
	{
		if (flags->precval == PF_FLAGS_DEFAULT)
			flags->precval = 0;
	}
	if (flags->precval > (int)(app->len))
	{
		if (app->str[0] == '-')
			vct_insert_nchar(app, 1, '0', flags->precval - app->len + 1);
		else
			vct_insert_nchar(app, 0, '0', flags->precval - app->len);
	}
	else if (ft_strcmp(arg_str, "0") == 0)
	{
		while (flags->precval < (int)(app->len))
			vct_cut(app);
	}
}

static int			pf_build_num_spec_wid_sign(t_vector *app)
{
	int				signidx;

	signidx = (int)(ft_strnchr_idx(app->str, '-', app->len));
	if (signidx == -1)
		signidx = (int)(ft_strnchr_idx(app->str, '+', app->len));
	if (signidx == -1)
		signidx = (int)(ft_strnchr_idx(app->str, ' ', app->len));
	return (signidx);
}

void				pf_build_num_spec_width(t_vector *app, t_flags *flags)
{
	int				signidx;

	signidx = pf_build_num_spec_wid_sign(app);
	if (flags->widval > (int)(app->len))
	{
		if (flags->mask & ISMINUS)
			vct_insert_nchar(app, app->len, ' ', \
							flags->widval - (int)(app->len));
		else
		{
			if ((flags->mask & ISZERO) && ((flags->mask & ISDOT) == 0))
			{
				if (signidx != -1)
					vct_insert_nchar(app, signidx + 1, '0', \
									flags->widval - app->len);
				else
					vct_insert_nchar(app, 0, '0', flags->widval - app->len);
			}
			else
				vct_insert_nchar(app, 0, ' ', flags->widval - app->len);
		}
	}
}
