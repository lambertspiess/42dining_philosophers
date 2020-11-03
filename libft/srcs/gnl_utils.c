/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <lspiess@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:35:03 by lspiess           #+#    #+#             */
/*   Updated: 2020/07/01 10:14:02 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

t_gnl_stream	*gnl_alloc_node(int fd)
{
	t_gnl_stream			*node;

	if (!(node = malloc(sizeof(t_gnl_stream))))
		return (NULL);
	node->fd = fd;
	node->prev = NULL;
	node->next = NULL;
	node->data = NULL;
	return (node);
}

void			gnl_free_node(t_gnl_stream **node)
{
	free((*node)->data);
	(*node)->fd = 0;
	(*node)->prev = NULL;
	(*node)->next = NULL;
	ft_free((void **)(node));
	*node = NULL;
}
