/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:05:56 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/10 10:51:24 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	If there is an overlap between two memory regions, ft_memmove makes sure
**	to avoid erasing bytes from the source before they can be copied to there
**	destination.
**	If *src is before *dst, copies backward starting from the end of *src.
**	If *src is after *dst, copies forward starting from the beginning of *src.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_p;
	unsigned char	*dst_p;

	if (len == 0 || dst == src)
		return (dst);
	src_p = (unsigned char *)src;
	dst_p = (unsigned char *)dst;
	if (src < dst)
	{
		src_p += len - 1;
		dst_p += len - 1;
		while (len-- > 0)
			*dst_p-- = *src_p--;
	}
	else
		while (len-- > 0)
			*dst_p++ = *src_p++;
	return (dst);
}
