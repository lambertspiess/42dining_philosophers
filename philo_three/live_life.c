/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:13:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/06 19:20:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_three.h"

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

void			*th_print_eat_and_decrement(void *p)
{
	t_philo			*philo;

	philo = (t_philo *)(p);
	print_is_eating(philo, philo->n, philo->last_meal - philo->time_to->start);
	sem_wait(&(philo->meals_left_sem));
	philo->meals_left -= 1;
	sem_post(&(philo->meals_left_sem));
	return (NULL);
}

void			*th_print_took_forks(void *p)
{
	t_philo			*philo;
	struct timeval	tv;

	philo = (t_philo *)(p);
	print_took_forks(philo, philo->n, \
						philo->last_meal - philo->time_to->start);
	return (NULL);
}

void			*eat(t_philo *philo)
{
	struct timeval	tv;
	unsigned long	t;
	pthread_t		idprint_eating;
	pthread_t		idprint_forks;

	sem_wait(philo->sem_forks);
	sem_wait(&(philo->last_meal_sem));
	philo->last_meal = gettime(&tv);
	pthread_create(&idprint_forks, NULL, th_print_took_forks, philo);
	pthread_create(&idprint_eating, NULL, th_print_eat_and_decrement, philo); 
	usleep(philo->time_to->eat_us);
	sem_post(philo->sem_forks);
	sem_post(&(philo->last_meal_sem));
	pthread_join(idprint_eating, NULL);
	pthread_join(idprint_forks, NULL);
	return (NULL);
}

void			simulate_philo(void *p)
{
	t_philo			*philo;
	struct timeval	tv;
	pthread_t		idpulse;
	int				ret;

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
	printf("WAITING FOR PTHREAD_JOIN\n");
	pthread_join(idpulse, NULL);
	printf("ABOUT TO EXIT SFSG\n");
	exit(philo->pulse_ret);
}

void			launch_simulation(t_philos *s)
{
	int				i;
	void			*ret;
	t_philo			*head;
	struct timeval	tv;

	head = s->philo;
	i = 0;
	s->time_to.start = gettime(&tv);
	while (i < s->n)
	{
		if (!(s->pids[i++] = fork()))
			simulate_philo(head);
		printf("CREATED PID %d FOR PHILO %d\n", s->pids[i - 1], i - 1);
		head = head->next;
	}
	kill_everybody(s);
}
