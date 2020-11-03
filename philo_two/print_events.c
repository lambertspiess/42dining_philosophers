/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:14:29 by user42            #+#    #+#             */
/*   Updated: 2020/11/03 17:16:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_two.h"

void		print_took_forks(t_philo *philo, int n, unsigned long ms)
{
	int			i;
	char		s[248];

	i = 0;
	i += ft_itoa_buf(s, ms);
	ft_memcpy(s + i, " - ", 3);
	i += 3;
	i += ft_itoa_buf(s + i, n);
	ft_memcpy(s + i, " has taken a fork\n\0", 19);
	i += 18;
	sem_wait(philo->man_down_sem);
	if (*(philo->man_down) == 0)
	{
		write(1, s, i);
		write(1, s, i);
	}
	sem_post(philo->man_down_sem);
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
	sem_wait(philo->man_down_sem);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	sem_post(philo->man_down_sem);
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
	sem_wait(philo->man_down_sem);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	sem_post(philo->man_down_sem);
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
	sem_wait(philo->man_down_sem);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	sem_post(philo->man_down_sem);
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
	sem_wait(philo->man_down_sem);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	sem_post(philo->man_down_sem);
}
