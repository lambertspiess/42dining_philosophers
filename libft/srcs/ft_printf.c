/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:25:01 by lspiess           #+#    #+#             */
/*   Updated: 2020/05/23 04:07:45 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_vector		*vct;
	int				ret;

	va_start(ap, format);
	vct = pf_asvct_printf(format, ap);
	vct_print(vct);
	ret = (int)(vct->len);
	vct_free(&vct);
	return (ret);
}

int				ft_printf_fd(int fd, const char *restrict format, ...)
{
	va_list			ap;
	t_vector		*vct;
	int				ret;

	va_start(ap, format);
	vct = pf_asvct_printf(format, ap);
	vct_printfd(vct, fd);
	ret = (int)(vct->len);
	vct_free(&vct);
	return (ret);
}

t_vector		*vct_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_vector		*vct;

	va_start(ap, format);
	vct = pf_asvct_printf(format, ap);
	return (vct);
}
