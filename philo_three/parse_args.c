/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:05:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/03 14:21:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_two.h"

void		error_exit(char *s)
{
	ft_putstr(s);
	exit(1);
}

static void	check_numstr(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || 57 < s[i])
			error_exit("Arg not a valid number\n");
		i++;
	}
}

void		parse_args(int ac, char **av, t_philos *s)
{
	int			i;

	if (ac < 5 || ac > 6)
		error_exit("Wrong number of args\n");
	i = 1;
	while (i < ac)
		check_numstr(av[i++]);
	i = 1;
	if ((s->n = ft_atoi(av[i++])) > 200)
		error_exit("Too many philosophers (>200)\n");
	if (s->n < 2)
		error_exit("Not enough philosophers (<2)\n");
	if ((s->time_to.die = ft_atoi(av[i++])) < 60)
		error_exit("Time to die too short (<60 ms)\n");
	if ((s->time_to.eat = ft_atoi(av[i++])) < 60)
		error_exit("Time to eat too short (<60 ms)\n");
	if ((s->time_to.sleep = ft_atoi(av[i++])) < 60)
		error_exit("Time to sleep too short (<60 ms)\n");
	if (i < ac)
		s->max_meals = ft_atoi(av[i]);
	else
		s->max_meals = -42;
	s->time_to.eat_us = s->time_to.eat * 1000;
	s->time_to.sleep_us = s->time_to.sleep * 1000;
	s->time_to.die_us = s->time_to.die * 1000;
}
