/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:25:16 by user42            #+#    #+#             */
/*   Updated: 2020/11/11 15:32:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_one.h"

static t_philos				g_phi;

int			main(int ac, char **av)
{
	ft_bzero(&g_phi, sizeof(t_philos));
	parse_args(ac, av, &g_phi);
	init_philosophers(&g_phi);
	launch_simulation(&g_phi);
	return (0);
}

/*
**printf("n = %d, timers : %d, %d, %d, max meals = %ld\n", \
** g_phi.n, g_phi.time_to.die, g_phi.time_to.eat, g_phi.time_to.sleep, \
** g_phi.max_meals);
*/

/*
**void		print_philosophers(t_philos *s)
**{
**	t_philo					*head;
**
**	head = s->philo;
**	while (head)
**	{
**		printf("n = %d (%p) left_fork = %p, right_fork = %p\n",
**			head->n, head, head->left_fork, head->right_fork);
**		head = head->right_fork->next;
**		sleep(1);
**	}
**}
*/
