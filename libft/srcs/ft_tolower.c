/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:17:45 by lspiess           #+#    #+#             */
/*   Updated: 2019/04/14 16:30:32 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_uppercase(int c)
{
	if (65 <= c && c <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int			ft_tolower(int c)
{
	if (is_uppercase(c))
		return (c + 32);
	return (c);
}
