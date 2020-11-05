/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:59:43 by lspiess           #+#    #+#             */
/*   Updated: 2020/10/16 21:39:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

static int	is_whitespace(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' \
		|| c == '\n' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	long long int	res;
	int				i;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && is_digit(str[i]))
	{
		res = ((res * 10) + (str[i] - '0'));
		i++;
	}
	return ((int)res * sign);
}
