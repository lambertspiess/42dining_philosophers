/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:50:59 by lspiess           #+#    #+#             */
/*   Updated: 2020/06/30 14:29:34 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
**		ft_strlcat
**
** SYNOPSIS
**		ft_strlcat(char *dst, const char *src, size_t size)
**
** PARAMETERS
**		char *dst			a pointer to the destination string
**		const char *src		a pointer to the source string
**		size_t size			the sizeof() the destination array.
**
** DESCRIPTION
**		strlcat is useful when concatenating chars fron a string into another,
**		without knowing if the destination array has enough memory to contain
**		the resulting concatenated string. If not, truncation will occur.
**		The return value can be used to check for truncation.
**
**	RETURN VALUE
**		The full length of the concatenated string strlcat attempted to create.
**		If the strlen of dst is smaller than the return value, it is sign that
**		the sizeof(dst) was too small and that truncation occurred.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t srclen;

	if (!src)
		srclen = 0;
	else
		srclen = ft_strlen(src);
	if (srclen + 1 < size)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	append;

	append = ft_strlen(src);
	i = 0;
	j = 0;
	while (dst[i] && size && i < size)
		i++;
	while (src[j] && size && i < size - 1)
	{
		dst[i++] = src[j++];
	}
	if (j != 0)
	{
		dst[i] = '\0';
		return (i - j + append);
	}
	return (i + append);
}
