/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:19:57 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:20:01 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

t_vector		*vct_reset(t_vector *vct, size_t size)
{
	if (vct == NULL)
		return (NULL);
	if (size < VCT_DEFSIZE)
		size = VCT_DEFSIZE;
	ft_strdel(&(vct->str));
	vct->str = (char *)ft_memalloc(size);
	if (vct->str == NULL)
		free(vct);
	else
	{
		vct->size = size;
		vct->quart = VCT_DEFQUART;
		vct->len = 0;
	}
	return (vct);
}
