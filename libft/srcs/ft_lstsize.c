/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:14:58 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:15:06 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"

int			ft_lstsize(t_list *lst)
{
	int			size;

	if (!(lst))
		return (0);
	else
	{
		size = 1;
		while (lst->next)
		{
			size++;
			lst = lst->next;
		}
	}
	return (size);
}
