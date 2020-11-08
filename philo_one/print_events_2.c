/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:37:12 by user42            #+#    #+#             */
/*   Updated: 2020/11/08 22:40:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers_philo_one.h"

void		print_took_fork_and_eat(t_philo *philo, int n, unsigned long ms)
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
	ft_memcpy(s + i, s, len);
	i += len;
	ft_memcpy(s + i, " is eating\n\0", 12);
	i += 12;
	pthread_mutex_lock(philo->man_down_lock);
	if (*(philo->man_down) == 0)
		write(1, s, i);
	pthread_mutex_unlock(philo->man_down_lock);
}
