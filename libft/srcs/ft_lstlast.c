/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:13:44 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:13:50 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list		*prev;

	if (!(lst))
		return (NULL);
	else
	{
		while (lst != NULL)
		{
			prev = lst;
			lst = lst->next;
		}
	}
	return (prev);
}
