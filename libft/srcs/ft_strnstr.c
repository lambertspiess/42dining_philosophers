/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:29:58 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/14 17:43:28 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (i < len))
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] && needle[j]  \
				&& (haystack[i + j] == needle[j]) && ((i + j) < len))
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)(&(haystack[i])));
		}
		i++;
	}
	return (NULL);
}
