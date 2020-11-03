/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:13:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/03 17:17:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_two.h"

//void			grab_right_then_left_fork(t_philo *philo)
//{
//	struct timeval	tv;
//
//	sem_wait(&(philo->right_fork->lock));
//	print_took_fork(philo, philo->n, gettime(&tv) - philo->time_to->start);
//	sem_wait(&(philo->left_fork->lock));
//	print_took_fork(philo, philo->n, gettime(&tv) - philo->time_to->start);
//}
//
//void			grab_left_then_right_fork(t_philo *philo)
//{
//	struct timeval	tv;
//
//	sem_wait(&(philo->left_fork->lock));
//	print_took_fork(philo, philo->n, gettime(&tv) - philo->time_to->start);
//	sem_wait(&(philo->right_fork->lock));
//	print_took_fork(philo, philo->n, gettime(&tv) - philo->time_to->start);
//}

void			*eat(t_philo *philo)
{
	struct timeval	tv;
	unsigned long	t;

	sem_wait(philo->sem_forks);
	print_took_forks(philo, philo->n, gettime(&tv) - philo->time_to->start);
	sem_wait(&(philo->last_meal_sem));
	philo->last_meal = gettime(&tv);
	print_is_eating(philo, philo->n, philo->last_meal - philo->time_to->start);
	philo->last_meal += philo->time_to->eat;
	sem_wait(&(philo->meals_left_sem));
	philo->meals_left -= 1;
	sem_post(&(philo->meals_left_sem));
	usleep(philo->time_to->eat_us);
	sem_post(philo->sem_forks);
	sem_post(&(philo->last_meal_sem));
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
	void			*ret;
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
