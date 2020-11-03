/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:26:51 by lspiess           #+#    #+#             */
/*   Updated: 2019/08/02 15:27:13 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	append len characters of a string at the end of another.
*/

char		*ft_strnjoin(char *s1, char *s2, int len)
{
	char	*ret;
	int		lens1;

	lens1 = ft_istrlen(s1);
	if (!(ret = malloc(sizeof(char) * lens1 + len + 1)))
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strncpy(&(ret[lens1]), s2, len);
	ret[lens1 + len] = '\0';
	return (ret);
}
