/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_philo_one.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:45:08 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 16:19:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_PHILO_ONE_H
# define HEADERS_PHILO_ONE_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

# define DIED 1
# define SATED 2

/*
** philosopher <-> fork <-> philosopher <-> fork <-> philosopher ...
*/

typedef struct			s_timers {
	unsigned long		eat;
	unsigned long		eat_us;
	unsigned long		sleep;
	unsigned long		sleep_us;
	unsigned long		die;
	unsigned long		die_us;
	unsigned long		start;
}						t_timers;

typedef struct			s_philo {
	int					n;
	struct s_timers		*time_to;
	int					time_eating;
	unsigned long		last_meal;
	pthread_mutex_t		last_meal_lock;
	int					meals_left;
	pthread_mutex_t		meals_left_lock;
	int					heartbeat;
	pthread_mutex_t		heartbeat_lock;
	struct s_fork		*left_fork;
	struct s_fork		*right_fork;
	int					*man_down;
	pthread_mutex_t		*man_down_lock;
}						t_philo;

typedef struct			s_fork {
	struct s_philo		*prev;
	struct s_philo		*next;
	pthread_mutex_t		lock;
}						t_fork;

typedef struct			s_philos {

	struct s_philo		*philo;
	struct s_timers		time_to;
	int					n;
	long				max_meals;
	int					man_down;
	pthread_mutex_t		man_down_lock;
}						t_philos;

void					ft_bzero(void *s, size_t n);
void					ft_putstr(const char *s);
int						ft_atoi(const char *str);
int						ft_itoa_buf(char *s, int i);
void					*ft_memcpy(void *dst, const void *src, size_t n);

void					error_exit(char *s);
unsigned long			gettime(struct timeval *tv);
void					print_took_fork(t_philo *philo, \
											int n, unsigned long ms);
void					print_took_fork_and_eat(t_philo *philo, \
											int n, unsigned long ms);
void					print_is_eating(t_philo *philo, \
											int n, unsigned long ms);
void					print_is_sleeping(t_philo *philo, \
											int n, unsigned long ms);
void					print_is_thinking(t_philo *philo, \
											int n, unsigned long ms);
void					print_died(t_philo *philo, \
											int n, unsigned long ms);
void					parse_args(int ac, char **av, t_philos *s);
void					init_philosophers(t_philos *s);
void					free_and_exit(t_philos *s, char *errmsg, int retval);
void					*simulate_philo(void *p);
void					launch_simulation(t_philos *s);
void					*th_decrement(void *p);

int						everyone_alive(t_philo *philo);
void					*take_pulse(void *p);
int						sated(t_philo *philo);

#endif
