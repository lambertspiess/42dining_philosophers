/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:17:20 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:17:21 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

t_vector		*vct_dup(t_vector *vct)
{
	t_vector		*new;

	if (vct == NULL || vct->str == NULL)
		return (NULL);
	if (!(new = malloc(sizeof(t_vector))))
		return (NULL);
	new->size = vct->size;
	new->len = vct->len;
	new->quart = vct->quart;
	if (!(new->str = malloc(new->size)))
		return (NULL);
	ft_memcpy(new->str, vct->str, vct->len);
	return (new);
}
