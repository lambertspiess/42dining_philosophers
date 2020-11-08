/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:12 by user42            #+#    #+#             */
/*   Updated: 2020/11/08 18:03:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_three.h"

/*
** Check if the philosopher has meals left
*/

int				sated(t_philo *philo)
{
	sem_wait(&(philo->meals_left_sem));
	if (philo->meals_left == 0)
	{
		sem_post(&(philo->meals_left_sem));
		return (1);
	}
	sem_post(&(philo->meals_left_sem));
	return (0);
}

void			*exit_fork(void)
{
	exit(0);
	return (NULL);
}

void			*died(t_philos *s, t_philo *philo, unsigned long t)
{
	sem_wait(s->man_down_sem);
	print_died(s, philo, philo->n, t - s->time_to.start);
	kill_pids(s);
	free_and_exit(s, NULL, 0);
	return (NULL);
}

void			*done_eating(t_philos *s)
{
	sem_wait(s->man_down_sem);
	kill_pids(s);
	free_and_exit(s, NULL, 0);
	return (NULL);
}

/*
** In a separate thread, monitor the time elapsed since the philosopher ate,
** and set the relevant variable philo->man_down to 1 if he's dead.
*/

void			*take_pulse(void *p)
{
	t_philos		*s;
	t_philo			*philo;
	struct timeval	tv;
	unsigned long	t;
	unsigned long	time_since_ate;

	s = (t_philos *)(p);
	philo = s->head;
	while (!sated(philo))
	{
		sem_wait(&(philo->last_meal_sem));
		t = gettime(&tv);
		sem_post(&(philo->last_meal_sem));
		time_since_ate = t - philo->last_meal;
		if (time_since_ate > philo->time_to->die)
			return (died(s, philo, t));
		{
//			print_died(s, philo, philo->n, t - philo->time_to->start);
//			sem_wait(s->man_down_sem);
//			kill_pids(s);
//			sem_post(s->man_down_sem);
//			philo->pulse_ret = 1;
//			return (NULL);
		}
		usleep(10);
	}
	return (done_eating(s));
}
