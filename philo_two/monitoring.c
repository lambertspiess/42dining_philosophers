/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:12 by user42            #+#    #+#             */
/*   Updated: 2020/11/07 00:13:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_two.h"

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

/*
** In a separate thread, monitor the time elapsed since the philosopher ate,
** and set the relevant variable philo->man_down to 1 if he's dead.
*/

void			*take_pulse(void *p)
{
	t_philo			*philo;
	struct timeval	tv;
	unsigned long	t;
	unsigned long	time_since_ate;

	philo = (t_philo *)(p);
	while (everyone_alive(philo) && !sated(philo))
	{
		sem_wait(&(philo->last_meal_sem));
		t = gettime(&tv);
		sem_post(&(philo->last_meal_sem));
		time_since_ate = t - philo->last_meal;
		if (time_since_ate > philo->time_to->die)
		{
			print_died(philo, philo->n, t - philo->time_to->start);
			sem_wait(philo->man_down_sem);
			*(philo->man_down) = 1;
			sem_post(philo->man_down_sem);
			return (NULL);
		}
		usleep(10);
	}
	return (NULL);
}

/*
** Check if everyone is still alive
*/

int				everyone_alive(t_philo *philo)
{
	sem_wait(philo->man_down_sem);
	if (*(philo->man_down))
	{
		sem_post(philo->man_down_sem);
		return (0);
	}
	sem_post(philo->man_down_sem);
	return (1);
}
