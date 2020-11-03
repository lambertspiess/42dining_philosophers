/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:39:36 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/17 20:48:30 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	np;

	if (n < 0)
	{
		write(1, "-", 1);
		np = (unsigned int)(n *= -1);
	}
	else
		np = (unsigned int)(n);
	if (np >= 10)
		ft_putnbr(np / 10);
	ft_putchar((char)(np % 10 + '0'));
}
