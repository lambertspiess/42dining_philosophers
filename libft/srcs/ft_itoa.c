/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:56:47 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/17 20:50:53 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_get_nbr_size(unsigned int nb)
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

char			*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	size;
	char			*s;
	unsigned int	i;

	nb = (n < 0 ? (unsigned int)(-n) : (unsigned int)(n));
	size = ft_get_nbr_size(nb);
	if (!(s = (char *)malloc(sizeof(char) * size + 1 + (n < 0 ? 1 : 0))))
		return (0);
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
