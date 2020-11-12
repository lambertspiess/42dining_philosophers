/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:14:29 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 16:29:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_three.h"

void		print_took_forks(t_philos *sp, int n, unsigned long ms)
{
	int			i;
	char		s[248];
	int			len;

	i = 0;
	i += ft_itoa_buf(s, ms);
	ft_memcpy(s + i, " - ", 3);
	i += 3;
	i += ft_itoa_buf(s + i, n);
	len = i;
	ft_memcpy(s + i, " has taken a fork\n\0", 19);
	i += 19;
	ft_strcpy(s + i, s);
	i *= 2;
	ft_memcpy(s + i, s, len);
	i += len;
	ft_memcpy(s + i, " is eating\n\0", 12);
	i += 12;
	sem_wait(sp->man_down_sem);
	write(1, s, i);
	sem_post(sp->man_down_sem);
}

void		print_is_eating(t_philos *sp, int n, unsigned long ms)
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
	sem_wait(sp->man_down_sem);
	write(1, s, i);
	sem_post(sp->man_down_sem);
}

void		print_is_sleeping(t_philos *sp, int n, unsigned long ms)
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
	sem_wait(sp->man_down_sem);
	write(1, s, i);
	sem_post(sp->man_down_sem);
}

void		print_is_thinking(t_philos *sp, int n, unsigned long ms)
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
	sem_wait(sp->man_down_sem);
	write(1, s, i);
	sem_post(sp->man_down_sem);
}

void		print_died(int n, unsigned long ms)
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
	write(1, s, i);
}
