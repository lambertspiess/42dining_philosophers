/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:15:19 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:15:20 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memft.h"

void		*ft_calloc(size_t nelem, size_t elemsize)
{
	void				*p;
	unsigned long long	total;

	total = nelem * elemsize;
	if (!(p = malloc(total)))
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
