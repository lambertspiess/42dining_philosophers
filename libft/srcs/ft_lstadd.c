/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:21:49 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/18 14:46:41 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*prev;
	t_list		*head;

	if (!alst)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	head = *alst;
	while (head)
	{
		prev = head;
		head = head->next;
	}
	prev->next = new;
	return ;
}
