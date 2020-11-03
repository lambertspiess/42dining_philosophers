/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:18:29 by lspiess           #+#    #+#             */
/*   Updated: 2020/06/01 08:37:27 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

static int		ft_count_tokens(const char *s)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (ft_is_space(s[i]) == 0)
			count++;
		while (s[i] && (ft_is_space(s[i]) == 0))
			i++;
		while (s[i] && (ft_is_space(s[i])))
			i++;
	}
	return (count);
}

void			*ft_free_tokens(char ***tokp)
{
	char			**tok;
	size_t			toki;

	tok = *tokp;
	toki = 0;
	while (tok[toki])
	{
		free(tok[toki]);
		tok[toki] = 0;
		toki++;
	}
	free (*tokp);
	return (NULL);
}

char			*ft_tokenize(char *s)
{
	size_t			i;
	char			*ret;

	i = 0;
	while (s[i] && (ft_is_space(s[i]) == 0))
		i++;
	if (!(ret = ft_strndup(s, i)))
		return (NULL);
	return (ret);
}

char			**ft_split_whitespace(const char *s)
{
	size_t			i;
	size_t			toki;
	char			**tok;

	if (!(tok = ft_memalloc(sizeof(char *) * (ft_count_tokens(s) + 1))))
		return (NULL);
	i = 0;
	toki = 0;
	while (s[i])
	{
		if (ft_is_space(s[i]) == 0)
		{
			if (!(tok[toki] = ft_tokenize((char *)(s + i))))
				return (ft_free_tokens(&tok));
			i += ft_strlen(tok[toki++]);
		}
		else
			i++;
	}
	return (tok);
}
