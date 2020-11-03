/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <lspiess@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:29:49 by lspiess           #+#    #+#             */
/*   Updated: 2020/07/01 10:41:44 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"
#define BUFFER_SIZE 4096

t_gnl_stream	*gnl_select_stream(t_gnl_stream **rootp, int fd)
{
	t_gnl_stream			*head;

	head = *rootp;
	if (!head)
		return (gnl_alloc_node(fd));
	while (head)
	{
		if (head->fd == fd)
			return (head);
		else if (head->next != NULL)
			head = head->next;
		else
			break ;
	}
	if (head->fd != fd)
	{
		if (!(head->next = gnl_alloc_node(fd)))
			return (NULL);
		head->next->prev = head;
		head = head->next;
		head->fd = fd;
	}
	return (head);
}

/*
** return 0 if head was freed, -1 on error, 1 otherwise
*/

static int		gnl_cutnfrom(t_gnl_stream *head, int len, t_gnl_stream **rootp)
{
	int						datalen;
	char					*to_free;
	t_gnl_stream			*prev;

	if (!head || !head->data)
		return (1);
	if (len == 0 || (datalen = ft_istrlen(head->data)) == 0)
		return (1);
	if (len == datalen)
	{
		if (!(prev = head->prev))
			*rootp = (head->next != NULL ? head->next : NULL);
		else
			prev->next = head->next;
		gnl_free_node(&head);
		return (0);
	}
	to_free = head->data;
	if (!(head->data = ft_strdup(head->data + len)))
		return (-1);
	ft_free((void **)(&to_free));
	return (1);
}

/*
** return 1 if a '\n' was found on the heap, 0 otherwise, -1 on error
*/

int				gnl_extract_line_from_heap(t_gnl_stream *head, \
									char **linep, t_gnl_stream **rootp)
{
	int			idx;

	if (!head || !head->data)
		return (0);
	if ((idx = ft_strchr_idx(head->data, '\n')) == -1)
		return (0);
	if (idx == 0)
	{
		*linep = ft_strdup("");
		gnl_cutnfrom(head, 1, rootp);
	}
	else if ((*linep = ft_strndup(head->data, idx)) != NULL)
	{
		if (gnl_cutnfrom(head, idx + 1, rootp) == -1)
			return (-1);
		return (1);
	}
	return (-1);
}

/*
** if a '\n' is on the heap, return 1, if not return 0, otherwise -1 on error
*/

int				gnl_store_on_heap(char *buf, t_gnl_stream *head)
{
	char			*dest;

	if (!(dest = ft_strjoin(head->data, buf)))
		return (-1);
	ft_free((void **)(&(head->data)));
	head->data = dest;
	if (ft_strchr(head->data, '\n') )
		return (1);
	return (0);
}

int				gnl_read(t_gnl_stream *head, char **linep, int fd, \
							t_gnl_stream **rootp)
{
	int				readret;
	char			buf[BUFFER_SIZE];
	int				ret;

	while (1)
	{
		if ((readret = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[readret] = '\0';
		if ((ret = gnl_store_on_heap(buf, head)) == 1)
			break ;
		if (readret < BUFFER_SIZE)
			break ;
	}
	if (gnl_extract_line_from_heap(head, linep, rootp) == 0)
	{
		if (ft_istrlen(head->data) == 0)
			*linep = ft_strdup("");
		else
			*linep = ft_strdup(head->data);
		gnl_cutnfrom(head, ft_istrlen(head->data), rootp);
		return (0);
	}
	return (1);
}

int				get_next_line(char **linep, int fd)
{
	static t_gnl_stream		*root = NULL;
	t_gnl_stream			*head;
	int						ret;

	sleep(1);
	if (fd < 0 || linep == NULL)
		return (-1);
	*linep = NULL;
	if (root == NULL)
	{
		root = gnl_alloc_node(fd);
		head = root;
	}
	else
		head = gnl_select_stream(&root, fd);
	if ((ret = gnl_extract_line_from_heap(head, linep, &root)) == 1)
		return (1);
	else if (ret == -1)
		return (-1);
	else
		return (gnl_read(head, linep, fd, &root));
}
