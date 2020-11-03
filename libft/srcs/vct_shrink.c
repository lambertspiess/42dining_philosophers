/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_shrink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:20:05 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:20:07 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

int				vct_shrink(t_vector *vct)
{
	char			*tmp;

	if (vct == NULL)
		return (SUCCESS);
	if (vct->size <= 64)
		return (SUCCESS);
	tmp = vct->str;
	while (vct->len <= vct->quart)
	{
		vct->size /= 2;
		vct->quart /= 2;
	}
	if (!(vct->str = malloc(vct->size)))
		return (FAILURE);
	ft_memcpy(vct->str, tmp, vct->len);
	free(tmp);
	return (SUCCESS);
}
