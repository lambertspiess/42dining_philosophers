/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:46:28 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:23:03 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *))
{
	t_list				*new;
	t_list				*root;

	if (!f || !lst)
		return (NULL);
	if (!(new = ft_lstnew((f)(lst->content))))
		return (NULL);
	lst = lst->next;
	root = new;
	while (lst)
	{
		if (!(new->next = ft_lstnew((f)(lst->content))))
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (root);
}
