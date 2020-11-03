/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:53:57 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/14 16:14:37 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void			*mem;
	void			*ptr;

	if (!(mem = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	ptr = mem;
	while (size-- > 0)
		*((char *)ptr++) = 0;
	return ((void *)mem);
}
