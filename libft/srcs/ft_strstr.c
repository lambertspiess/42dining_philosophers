/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:23:29 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/14 17:51:06 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	unsigned long	i;
	unsigned long	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] && needle[j] \
				&& (haystack[i + j] == needle[j]))
				j++;
			if (needle[j] == '\0')
				return ((char *)(&(haystack[i])));
		}
		i++;
	}
	return (NULL);
}
