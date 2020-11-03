/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:09:58 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:10:04 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convft.h"

char				*ft_utoa(unsigned int n)
{
	size_t			size;
	char			*ret;
	size_t			i;

	size = ft_get_nbr_size(n);
	if (!(ret = malloc(size + 1)))
		return (NULL);
	ret[size] = '\0';
	i = size - 1;
	while (n >= 10)
	{
		ret[i] = (char)(n % 10 + '0');
		n /= 10;
		i--;
	}
	ret[i] = (char)(n % 10 + '0');
	return (ret);
}

char				*ft_ultoa(unsigned long n)
{
	size_t			size;
	char			*ret;
	size_t			i;

	size = ft_get_lnbr_size(n);
	if (!(ret = malloc(size + 1)))
		return (NULL);
	ret[size] = '\0';
	i = size - 1;
	while (n >= 10)
	{
		ret[i] = (char)(n % 10 + '0');
		n /= 10;
		i--;
	}
	ret[i] = (char)(n % 10 + '0');
	return (ret);
}

char				*ft_ulltoa(unsigned long long n)
{
	size_t			size;
	char			*ret;
	size_t			i;

	size = ft_get_llnbr_size(n);
	if (!(ret = malloc(size + 1)))
		return (NULL);
	ret[size] = '\0';
	i = size - 1;
	while (n >= 10)
	{
		ret[i] = (char)(n % 10 + '0');
		n /= 10;
		i--;
	}
	ret[i] = (char)(n % 10 + '0');
	return (ret);
}
