/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:13:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 16:22:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_two.h"

void			*th_decrement(void *p)
{
	t_philo			*philo;

	philo = (t_philo *)(p);
	sem_wait(&(philo->meals_left_sem));
	philo->meals_left -= 1;
	sem_post(&(philo->meals_left_sem));
	return (NULL);
}

void			*th_print_took_forks(void *p)
{
	t_philo			*philo;

	philo = (t_philo *)(p);
	print_took_forks(philo, philo->n, \
						philo->last_meal - philo->time_to->start);
	return (NULL);
}

void			*eat(t_philo *philo)
{
	struct timeval	tv;
	pthread_t		id_decrement;
	pthread_t		idprint_forks;

	sem_wait(philo->sem_forks);
	sem_wait(&(philo->last_meal_sem));
	philo->last_meal = gettime(&tv);
	pthread_create(&idprint_forks, NULL, th_print_took_forks, philo);
	pthread_create(&id_decrement, NULL, th_decrement, philo);
	usleep(philo->time_to->eat_us);
	sem_post(philo->sem_forks);
	sem_post(&(philo->last_meal_sem));
	pthread_detach(idprint_forks);
	pthread_detach(id_decrement);
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
		head = head->next;
	}
	i = 0;
	while (i < s->n)
		pthread_join(ids[i++], NULL);
	free_and_exit(s, "Exiting...\n", 0);
}
