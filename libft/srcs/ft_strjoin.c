/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:46:22 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/10 11:17:51 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_l(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char					*ft_strjoin(char const *s1, char const *s2)
{
	long long	i;
	long long	j;
	char		*sc;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (s1 ? ft_strdup((char *)s1) : ft_strdup((char *)s2));
	if (!(sc = (char *)malloc(sizeof(char) * (ft_l(s1) + ft_l(s2) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		sc[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i])
	{
		sc[j] = s2[i];
		j++;
	}
	sc[j] = '\0';
	return (sc);
}
