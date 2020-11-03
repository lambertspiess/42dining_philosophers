/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:31:58 by lspiess           #+#    #+#             */
/*   Updated: 2020/06/30 13:52:30 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** counts the number of chars inside a string (null-term excluded)
*/

int		ft_istrlen(char *s)
{
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}
