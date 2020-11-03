/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:32:04 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/18 17:44:24 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*p;
	long	i;

	i = 0;
	p = (char *)s;
	while (p[i])
		i++;
	while (i >= 0)
	{
		if (p[i] == ((char)(c)))
			return (&(p[i]));
		i--;
	}
	return (NULL);
}
