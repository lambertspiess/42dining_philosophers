/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:08:53 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:09:36 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MINUS 1

unsigned int	ft_get_lnbr_size(unsigned long nb)
{
	unsigned int		size;

	size = 0;
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size + 1);
}

char			*ft_ltoa(long n)
{
	unsigned long		nb;
	unsigned int		size;
	char				*s;
	unsigned int		i;

	nb = (n < 0 ? (unsigned long)(-n) : (unsigned long)(n));
	size = ft_get_lnbr_size(nb);
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
