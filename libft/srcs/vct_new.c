/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:19:02 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:19:04 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

t_vector		*vct_new(size_t size)
{
	t_vector		*vct;

	vct = malloc(sizeof(t_vector));
	if (vct != NULL)
	{
		vct->str = NULL;
		vct_reset(vct, size);
	}
	return (vct);
}
