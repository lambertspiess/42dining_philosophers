/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:25:16 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 00:04:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_two.h"

static t_philos				g_phi;

int			main(int ac, char **av)
{
	ft_bzero(&g_phi, sizeof(t_philos));
	parse_args(ac, av, &g_phi);
	init_philosophers(&g_phi);
	launch_simulation(&g_phi);
	return (0);
}
