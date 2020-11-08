/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:13:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/08 18:19:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_three.h"

void			*th_decrement(void *p)
{
	t_philos		*s;
	t_philo			*philo;

	s = (t_philos *)(p);
	philo = s->head;
//	print_is_eating(s, philo, philo->n,
//						philo->last_meal - philo->time_to->start);
	sem_wait(&(philo->meals_left_sem));
	philo->meals_left -= 1;
	sem_post(&(philo->meals_left_sem));
	return (NULL);
}

void			*th_print_took_forks(void *p)
{
	t_philos		*s;
	struct timeval	tv;

	s = (t_philos *)(p);
	print_took_forks(s, s->head, s->head->n, \
						s->head->last_meal - s->time_to.start);
	return (NULL);
}

void			*eat(t_philos *s, t_philo *philo)
{
	struct timeval	tv;
	unsigned long	t;
	pthread_t		idprint_eating;
	pthread_t		idprint_forks;

	int checksem; sem_getvalue(s->sem_forks, &checksem);
//	printf("\t%d waiting for sem_forks of value %d\n", philo->n, checksem);
	sem_wait(s->sem_forks);
//	printf("\t%d got sem_forks\n", philo->n);
	sem_wait(&(philo->last_meal_sem));
	philo->last_meal = gettime(&tv);
	pthread_create(&idprint_forks, NULL, th_print_took_forks, s);
	pthread_create(&idprint_eating, NULL, th_decrement, s); 
	usleep(philo->time_to->eat_us);
	sem_post(s->sem_forks);
	sem_post(&(philo->last_meal_sem));
	pthread_join(idprint_eating, NULL);
	pthread_join(idprint_forks, NULL);
	return (NULL);
}

void			simulate_philo(t_philos *s, t_philo *philo)
{
	struct timeval	tv;
	pthread_t		idpulse;
	int				ret;

	philo->last_meal = philo->time_to->start;
	s->man_down_sem = sem_open("/man_down_sem", O_CREAT, S_IRWXU, 1);
	s->sem_forks = sem_open("/forks_sem", O_CREAT, S_IRWXU, s->n / 2);
	pthread_create(&idpulse, NULL, take_pulse, s);
	while (1)
	{
		eat(s, philo);
		if (sated(philo))
			break ;
		print_is_sleeping(s, philo, philo->n, \
							gettime(&tv) - philo->time_to->start);
		usleep(philo->time_to->sleep_us);
		print_is_thinking(s, philo, philo->n, \
							gettime(&tv) - philo->time_to->start);
	}
	pthread_join(idpulse, NULL);
//	kill_pids(s);
	free_and_exit(s, NULL, 0);
}

void			launch_simulation(t_philos *s)
{
	int				i;
	void			*ret;
	struct timeval	tv;
	int				waitpidret;

	i = 0;
	s->head = s->philo;
	s->time_to.start = gettime(&tv);
	while (i < s->n)
	{
		if (!(s->pids[i++] = fork()))
			simulate_philo(s, s->head);
		s->head = s->head->next;
	}
//	i = 0;
	waitpid(-1, &waitpidret, 0);
	usleep(1000000);
	free_and_exit(s, NULL, 0);
}
