/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:14:29 by user42            #+#    #+#             */
/*   Updated: 2020/10/31 01:17:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_one.h"

void		print_took_fork(t_philo *philo, int n, unsigned long ms)
{
	int			i;
	char		s[124];

	i = 0;
	i += ft_itoa_buf(s, ms);
	ft_memcpy(s + i, " - ", 3);
	i += 3;
	i += ft_itoa_buf(s + i, n);
	ft_memcpy(s + i, " has taken a fork\n\0", 19);
	i += 18;
	pthread_mutex_lock(philo->man_down_lock);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	pthread_mutex_unlock(philo->man_down_lock);
}

void		print_is_eating(t_philo *philo, int n, unsigned long ms)
{
	int			i;
	char		s[124];

	i = 0;
	i += ft_itoa_buf(s, ms);
	ft_memcpy(s + i, " - ", 3);
	i += 3;
	i += ft_itoa_buf(s + i, n);
	ft_memcpy(s + i, " is eating\n\0", 12);
	i += 12;
	pthread_mutex_lock(philo->man_down_lock);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	pthread_mutex_unlock(philo->man_down_lock);
}

void		print_is_sleeping(t_philo *philo, int n, unsigned long ms)
{
	int			i;
	char		s[124];

	i = 0;
	i += ft_itoa_buf(s, ms);
	ft_memcpy(s + i, " - ", 3);
	i += 3;
	i += ft_itoa_buf(s + i, n);
	ft_memcpy(s + i, " is sleeping\n\0", 14);
	i += 14;
	pthread_mutex_lock(philo->man_down_lock);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	pthread_mutex_unlock(philo->man_down_lock);
}

void		print_is_thinking(t_philo *philo, int n, unsigned long ms)
{
	int			i;
	char		s[124];

	i = 0;
	i += ft_itoa_buf(s, ms);
	ft_memcpy(s + i, " - ", 3);
	i += 3;
	i += ft_itoa_buf(s + i, n);
	ft_memcpy(s + i, " is thinking\n\0", 14);
	i += 14;
	pthread_mutex_lock(philo->man_down_lock);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	pthread_mutex_unlock(philo->man_down_lock);
}

void		print_died(t_philo *philo, int n, unsigned long ms)
{
	int			i;
	char		s[124];

	i = 0;
	i += ft_itoa_buf(s, ms);
	ft_memcpy(s + i, " - ", 3);
	i += 3;
	i += ft_itoa_buf(s + i, n);
	ft_memcpy(s + i, " has died\n\0", 10);
	i += 10;
	pthread_mutex_lock(philo->man_down_lock);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	pthread_mutex_unlock(philo->man_down_lock);
}
