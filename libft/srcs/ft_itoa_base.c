/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:09:42 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:10:19 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convft.h"

#define NULLTER 1

char		*ft_itoa_base(int n, int base)
{
	int					i;
	char				*s;
	char				buf[100];
	char				*ret;

	s = "0123456789abcdef";
	if (base == 10)
		return (ft_itoa(n));
	if (n == 0)
		return (ft_strdup("0"));
	ft_memset(buf, -1, 100);
	buf[99] = '\0';
	i = 98;
	while (n)
	{
		buf[i] = s[n % base];
		n /= base;
		i--;
	}
	ret = ft_mmalloc(100 - i);
	++i;
	ret = ft_strcpy(ret, &(buf[i]));
	return (ret);
}

char		*ft_ltoa_base(long n, int base)
{
	int					i;
	char				*s;
	char				buf[100];
	char				*ret;

	s = "0123456789abcdef";
	if (base == 10)
		return (ft_ltoa(n));
	if (n == 0)
		return (ft_strdup("0"));
	ft_memset(buf, -1, 100);
	buf[99] = '\0';
	i = 98;
	while (n)
	{
		buf[i] = s[n % base];
		n /= base;
		i--;
	}
	ret = ft_mmalloc(100 - i);
	++i;
	ret = ft_strcpy(ret, &(buf[i]));
	return (ret);
}

char		*ft_lltoa_base(long long n, int base)
{
	int					i;
	char				*s;
	char				buf[100];
	char				*ret;

	s = "0123456789abcdef";
	if (base == 10)
		return (ft_lltoa(n));
	if (n == 0)
		return (ft_strdup("0"));
	ft_memset(buf, -1, 100);
	buf[99] = '\0';
	i = 98;
	while (n)
	{
		buf[i] = s[n % base];
		n /= base;
		i--;
	}
	ret = ft_mmalloc(100 - i);
	++i;
	ret = ft_strcpy(ret, &(buf[i]));
	return (ret);
}
