/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:30:38 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:17:01 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"
#include "memft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && (ft_strchr(set, s1[i]) != 0))
		i++;
	j = i;
	while (s1[j])
		j++;
	j--;
	while (j > i && (ft_strchr(set, s1[j]) != 0))
		j--;
	if (j <= i)
		return (ft_strdup(""));
	return (ft_strndup(s1 + i, j - i + 1));
}
