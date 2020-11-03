/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:58:03 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/17 17:21:47 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	np;

	if (n < 0)
	{
		write(fd, "-", 1);
		np = (unsigned int)(n *= -1);
	}
	else
		np = (unsigned int)n;
	if (np >= 10)
		ft_putnbr_fd(np / 10, fd);
	ft_putchar_fd((char)(np % 10 + '0'), fd);
}
