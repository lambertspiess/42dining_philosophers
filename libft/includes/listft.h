/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:48:10 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:48:12 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTFT_H
# define LISTFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstclear(t_list **alst, void (*del)(void *));
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);

#endif
