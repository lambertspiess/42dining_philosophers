/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:16:19 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:16:21 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strchr_idx(const char *s, int c)
{
	unsigned long	i;
	unsigned long	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	i = 0;
	while ((i < len) && (s[i] != (char)c))
		i++;
	if (i == len)
	{
		if (c != '\0')
			return (-1);
	}
	return (i);
}

int				ft_strnchr_idx(const char *s, int c, size_t n)
{
	unsigned long	i;

	if (!s)
		return (-1);
	i = 0;
	while ((i < n) && (s[i] != (char)c))
		i++;
	if (i == n)
	{
		if (c != '\0')
			return (-1);
	}
	return (i);
}
