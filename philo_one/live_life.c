/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:13:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 16:17:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_one.h"

void			grab_right_then_left_fork(t_philo *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(&(philo->right_fork->lock));
	print_took_fork(philo, philo->n, gettime(&tv) - philo->time_to->start);
	pthread_mutex_lock(&(philo->left_fork->lock));
	print_took_fork_and_eat(philo, philo->n, \
								gettime(&tv) - philo->time_to->start);
}

void			grab_left_then_right_fork(t_philo *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(&(philo->left_fork->lock));
	print_took_fork(philo, philo->n, gettime(&tv) - philo->time_to->start);
	pthread_mutex_lock(&(philo->right_fork->lock));
	print_took_fork_and_eat(philo, philo->n, \
								gettime(&tv) - philo->time_to->start);
}

void			*eat(t_philo *philo)
{
	struct timeval	tv;
	pthread_t		iddecrement;

	if (philo->n % 2 == 0)
		grab_right_then_left_fork(philo);
	else
		grab_left_then_right_fork(philo);
	pthread_mutex_lock(&(philo->last_meal_lock));
	pthread_create(&iddecrement, NULL, th_decrement, philo);
	usleep(philo->time_to->eat_us);
	philo->last_meal = gettime(&tv);
	pthread_mutex_unlock(&(philo->last_meal_lock));
	pthread_mutex_unlock(&(philo->left_fork->lock));
	pthread_mutex_unlock(&(philo->right_fork->lock));
	pthread_detach(iddecrement);
	return (NULL);
}

void			*simulate_philo(void *p)
{
	t_philo			*philo;
	struct timeval	tv;
	pthread_t		idpulse;

	philo = (t_philo *)(p);
	philo->last_meal = philo->time_to->start;
	pthread_create(&idpulse, NULL, take_pulse, philo);
	while (everyone_alive(philo))
	{
		eat(philo);
		if (sated(philo))
			break ;
		print_is_sleeping(philo, philo->n, \
							gettime(&tv) - philo->time_to->start);
		usleep(philo->time_to->sleep_us);
		print_is_thinking(philo, philo->n, \
							gettime(&tv) - philo->time_to->start);
	}
	pthread_join(idpulse, NULL);
	return (NULL);
}

void			launch_simulation(t_philos *s)
{
	int				i;
	pthread_t		ids[200];
	t_philo			*head;
	struct timeval	tv;

	ft_bzero(ids, sizeof(ids));
	head = s->philo;
	i = 0;
	s->time_to.start = gettime(&tv);
	while (i < s->n)
	{
		pthread_create(&(ids[i++]), NULL, simulate_philo, head);
		head = head->right_fork->next;
	}
	i = 0;
	while (i < s->n)
		pthread_join(ids[i++], NULL);
	free_and_exit(s, "Exiting...\n", 0);
}
