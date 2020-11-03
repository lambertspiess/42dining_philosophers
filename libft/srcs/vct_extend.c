/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:18:08 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:26:07 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				vct_extend(t_vector *vct, size_t expected_len)
{
	char			*tmp;
	size_t			i;

	if (vct == NULL || vct->size == 0)
		return (SUCCESS);
	tmp = vct->str;
	while (vct->size <= expected_len)
	{
		vct->size *= 2;
		vct->quart *= 2;
	}
	if (!(vct->str = malloc(vct->size)))
		return (FAILURE);
	i = 0;
	while (i < vct->len)
	{
		vct->str[i] = tmp[i];
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (SUCCESS);
}
