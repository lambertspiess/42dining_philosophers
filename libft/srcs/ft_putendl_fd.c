/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:40:59 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/08 14:29:55 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i++])
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}
