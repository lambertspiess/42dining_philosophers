/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strneq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:42:28 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/07 16:27:34 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned long i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n < 1)
		return (1);
	while (i < n)
	{
		if (s1[i] == s2[i] && s1[i] && s2[i])
			i++;
		else
		{
			break ;
		}
	}
	if (i == n || (!s1[i] && !s2[i]))
		return (1);
	else
	{
		return (0);
	}
}
