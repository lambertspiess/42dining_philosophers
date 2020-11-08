/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:53:29 by user42            #+#    #+#             */
/*   Updated: 2020/11/08 23:53:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_one.h"

void			*th_decrement(void *p)
{
	t_philo			*philo;

	philo = (t_philo *)(p);
	pthread_mutex_lock(&(philo->meals_left_lock));
	philo->meals_left -= 1;
	pthread_mutex_unlock(&(philo->meals_left_lock));
	return (NULL);
}
