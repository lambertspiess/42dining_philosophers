/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_philo_three.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:45:08 by user42            #+#    #+#             */
/*   Updated: 2020/11/06 19:06:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_PHILO_TWO_H
# define HEADERS_PHILO_TWO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>

# define MAN_DOWN_NSEM "/man_down_sem"
# define FORKS_NSEM  "/forks_sem"

typedef struct			s_timers {
	int					eat;
	unsigned long		eat_us;
	int					sleep;
	unsigned long		sleep_us;
	int					die;
	unsigned long		die_us;
	unsigned long		start;
}						t_timers;

typedef struct			s_philo {
	int					n;
	struct s_timers		*time_to;
	int					time_eating;
	unsigned long		last_meal;
	sem_t				last_meal_sem;
	int					meals_left;
	sem_t				meals_left_sem;
	int					heartbeat;
	sem_t				heartbeat_sem;
	int					*man_down;
	sem_t				*man_down_sem;
	sem_t				*sem_forks;
	struct s_philo		*next;
	int					pulse_ret;
}						t_philo;

typedef struct			s_philos {

	struct s_philo		*philo;
	struct s_timers		time_to;
	int					pids[200];
	int					n;
	long				max_meals;
	int					man_down;
	sem_t				*man_down_sem;
	sem_t				*sem_forks;
}						t_philos;

void					ft_bzero(void *s, size_t n);
void					ft_putstr(const char *s);
int						ft_atoi(const char *str);
int						ft_itoa_buf(char *s, int i);
void					*ft_memcpy(void *dst, const void *src, size_t n);
char					*ft_strcpy(char *dst, const char *src);

void					error_exit(char *s);
unsigned long			gettime(struct timeval *tv);
void					print_took_forks(t_philo *philo, \
											int n, unsigned long ms);
void					print_is_eating(t_philo *philo, \
											int n, unsigned long ms);
void					print_is_sleeping(t_philo *philo, \
											int n, unsigned long ms);
void					print_is_thinking(t_philo *philo, \
											int n, unsigned long ms);
void					print_died(t_philo *philo, \
											int n, unsigned long ms);

void					*take_pulse(void *p);
int						sated(t_philo *philo);
int						everyone_alive(t_philo *philo);

void					parse_args(int ac, char **av, t_philos *s);
void					init_philosophers(t_philos *s);
void					free_and_exit(t_philos *s, char *errmsg, int retval);
void					simulate_philo(void *p);
void					launch_simulation(t_philos *s);
int						everyone_alive(t_philo *philo);
void					kill_everybody(t_philos *s);

#endif
