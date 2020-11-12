/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:14:03 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 16:17:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_one.h"

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
		head = head->right_fork->next;
		pthread_mutex_destroy(&(to_free->last_meal_lock));
		pthread_mutex_destroy(&(to_free->heartbeat_lock));
		pthread_mutex_destroy(&(to_free->right_fork->lock));
		pthread_mutex_destroy(&(to_free->meals_left_lock));
		ft_bzero(to_free->right_fork, sizeof(t_fork));
		free(to_free->right_fork);
		ft_bzero(to_free, sizeof(t_philo));
		free(to_free);
		i++;
	}
	pthread_mutex_destroy(&(s->man_down_lock));
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
	pthread_mutex_init(&(philo->last_meal_lock), NULL);
	pthread_mutex_init(&(philo->heartbeat_lock), NULL);
	pthread_mutex_init(&(philo->meals_left_lock), NULL);
	philo->man_down = &(s->man_down);
	philo->man_down_lock = &(s->man_down_lock);
	return (philo);
}

t_fork		*alloc_fork(t_philo *prev, t_philo *next)
{
	t_fork		*fork;

	if (!(fork = malloc(sizeof(t_fork))))
		return (NULL);
	ft_bzero(fork, sizeof(t_fork));
	fork->prev = prev;
	fork->next = next;
	pthread_mutex_init(&(fork->lock), NULL);
	return (fork);
}

void		init_philosophers(t_philos *s)
{
	int				i;
	t_philo			*root;
	t_philo			*new;

	s->man_down = 0;
	pthread_mutex_init(&(s->man_down_lock), NULL);
	if (!(s->philo = alloc_philo(0, s)))
		error_exit("Malloc failure in alloc_philo()\n");
	root = s->philo;
	i = 0;
	while (++i < s->n)
	{
		if (!(new = alloc_philo(i, s)))
			free_and_exit(s, "Malloc failure in alloc_philo\n", 1);
		if (!(s->philo->right_fork = alloc_fork(s->philo, new)))
			free_and_exit(s, "Malloc failure in alloc_fork\n", 1);
		new->left_fork = s->philo->right_fork;
		s->philo = new;
	}
	if (!(s->philo->right_fork = alloc_fork(s->philo, root)))
		free_and_exit(s, "Malloc failure in alloc_fork\n", 1);
	root->left_fork = s->philo->right_fork;
	s->philo = root;
}
