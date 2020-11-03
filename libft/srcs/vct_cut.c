/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:17:14 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:23:21 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

int				vct_cut(t_vector *vct)
{
	if (vct == NULL || vct->str == NULL || vct->len == 0)
		return (SUCCESS);
	vct->str[vct->len - 1] = '\0';
	vct->len--;
	if (vct->len <= vct->quart)
	{
		if (vct_shrink(vct) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

/*
** DESCRIPTION :
** Cuts the string from the index idx (included) replacing it with '\0'
*/

int				vct_cutfrom(t_vector *vct, size_t idx)
{
	size_t			cutsnb;

	if (vct == NULL || vct->str == NULL || vct->len == 0)
		return (SUCCESS);
	cutsnb = vct->len - idx;
	while (cutsnb > 0)
	{
		if (vct_cut(vct) == FAILURE)
			return (FAILURE);
		cutsnb--;
	}
	return (SUCCESS);
}

/*
** DESCRIPTION :
** Cuts n chars from the string starting from the index idx (included)
*/

int				vct_cutnfrom(t_vector *vct, size_t idx, size_t n)
{
	size_t			i;
	size_t			j;

	if (vct == NULL || vct->str == NULL || idx + n > vct->len)
		return (SUCCESS);
	i = idx;
	j = idx + n;
	while (j < vct->size)
	{
		vct->str[i] = vct->str[j];
		i++;
		j++;
	}
	vct->len -= n;
	if (vct->len <= vct->quart)
	{
		if (vct_shrink(vct) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
