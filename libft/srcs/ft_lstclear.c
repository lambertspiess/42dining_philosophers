/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:04:53 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/08 19:32:38 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **alst, void (*del)(void *))
{
	if (*alst)
		del((*alst)->content);
	if ((*alst)->next)
		ft_lstclear(&((*alst)->next), del);
	free(*alst);
	*alst = NULL;
}
