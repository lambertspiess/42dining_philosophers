/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:14:03 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 16:21:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_two.h"

void		free_and_exit(t_philos *s, char *errmsg, int retval)
{
	int			i;
	t_philo		*to_free;
	t_philo		*head;

	(void)(errmsg);
	i = 0;
	head = s->philo;
	while (i < s->n)
	{
		to_free = head;
		head = head->next;
		sem_close(&(to_free->last_meal_sem));
		sem_close(&(to_free->heartbeat_sem));
		sem_close(&(to_free->meals_left_sem));
		ft_bzero(to_free, sizeof(t_philo));
		free(to_free);
		i++;
	}
	sem_close(&(s->man_down_sem));
	sem_close(&(s->sem_forks));
	exit(retval);
}

t_philo		*alloc_philo(int n, t_philos *s)
{
	t_philo		*philo;

	if (!(philo = malloc(sizeof(t_philo))))
		return (NULL);
	ft_bzero(philo, sizeof(t_philo));
	philo->meals_left = s->max_meals;
	philo->time_to = &(s->time_to);
	philo->heartbeat = 1;
	philo->n = n + 1;
	sem_init(&(philo->last_meal_sem), 0, 1);
	sem_init(&(philo->heartbeat_sem), 0, 1);
	sem_init(&(philo->meals_left_sem), 0, 1);
	philo->man_down = &(s->man_down);
	philo->man_down_sem = &(s->man_down_sem);
	philo->sem_forks = &(s->sem_forks);
	philo->next = NULL;
	return (philo);
}

void		init_philosophers(t_philos *s)
{
	int				i;
	t_philo			*root;

	s->man_down = 0;
	sem_init(&(s->man_down_sem), 0, 1);
	sem_init(&(s->sem_forks), 0, s->n / 2);
	if (!(s->philo = alloc_philo(0, s)))
		error_exit("Malloc failure in alloc_philo()\n");
	root = s->philo;
	i = 0;
	while (++i < s->n)
	{
		if (!(s->philo->next = alloc_philo(i, s)))
			free_and_exit(s, "Malloc failure in alloc_philo\n", 1);
		s->philo = s->philo->next;
	}
	s->philo = root;
}
