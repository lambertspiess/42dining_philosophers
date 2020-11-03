/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:56:47 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/22 18:12:53 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MINUS 1

unsigned int	ft_get_llnbr_size(unsigned long long nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size + 1);
}

char			*ft_lltoa(long long n)
{
	unsigned long long	nb;
	unsigned int		size;
	char				*s;
	unsigned int		i;

	nb = (n < 0 ? (unsigned long long)(-n) : (unsigned long long)(n));
	size = ft_get_llnbr_size(nb);
	if (!(s = (char *)malloc(sizeof(char) * size + 1 + (n < 0 ? MINUS : 0))))
		return (NULL);
	if (n < 0 && (s[0] = '-'))
		size++;
	s[size] = '\0';
	i = size - 1;
	while (nb >= 10)
	{
		s[i] = (char)(nb % 10 + '0');
		nb /= 10;
		i--;
	}
	s[i] = (char)(nb % 10 + '0');
	return (s);
}
