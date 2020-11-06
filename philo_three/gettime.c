/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <root@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 22:49:59 by user42            #+#    #+#             */
/*   Updated: 2020/11/06 15:37:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_philo_three.h"

unsigned long	gettime(struct timeval *tv)
{
	gettimeofday(tv, NULL);
	return (tv->tv_sec * 1000 + tv->tv_usec * 0.001);
}
