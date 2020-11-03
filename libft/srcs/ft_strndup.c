/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:34:34 by lspiess           #+#    #+#             */
/*   Updated: 2020/01/15 20:47:47 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**	Duplicates n chars of a char array into a newly malloc'd char array that
**	is then null-terminated. The len specified must not exceed the length of
**	the source string.
**
** PARAMETERS
**	char *src	--	the source string
**	int len		--	the number of bytesto copy
*/

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	size_t	i;
	char	*ret;

	if (len == 0)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = '\0';
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	return (ret);
}
