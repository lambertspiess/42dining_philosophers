/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:12 by user42            #+#    #+#             */
/*   Updated: 2020/11/06 23:19:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_one.h"

/*
** Check if the philosopher has meals left
*/

int				sated(t_philo *philo)
{
	pthread_mutex_lock(&(philo->meals_left_lock));
	if (philo->meals_left == 0)
	{
		pthread_mutex_unlock(&(philo->meals_left_lock));
		return (1);
	}
	pthread_mutex_unlock(&(philo->meals_left_lock));
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
		pthread_mutex_lock(&(philo->last_meal_lock));
		t = gettime(&tv);
		pthread_mutex_unlock(&(philo->last_meal_lock));
		time_since_ate = t - philo->last_meal;
		if (time_since_ate > philo->time_to->die)
		{
			print_died(philo, philo->n, t - philo->time_to->start);
			pthread_mutex_lock(philo->man_down_lock);
			*(philo->man_down) = 1;
			pthread_mutex_unlock(philo->man_down_lock);
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
	pthread_mutex_lock(philo->man_down_lock);
	if (*(philo->man_down))
	{
		pthread_mutex_unlock(philo->man_down_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->man_down_lock);
	return (1);
}
