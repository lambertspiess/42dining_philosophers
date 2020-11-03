/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_app.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:17:09 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:23:13 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

int				vct_app_char(t_vector *vct, char c)
{
	if (vct == NULL || vct->str == NULL)
		return (FAILURE);
	if (vct->len + 1 >= vct->size)
	{
		if (vct_extend(vct, vct->len + 1) == FAILURE)
			return (FAILURE);
	}
	vct->str[vct->len] = c;
	vct->len++;
	vct->str[vct->len] = '\0';
	return (SUCCESS);
}

int				vct_app_str(t_vector *vct, char *addens)
{
	unsigned long		i;
	size_t				expected_len;

	if (addens == NULL || vct == NULL || vct->str == NULL)
		return (SUCCESS);
	expected_len = vct->len + ft_strlen(addens);
	if (expected_len >= vct->size)
	{
		if (vct_extend(vct, expected_len) == FAILURE)
			return (FAILURE);
	}
	i = 0;
	while (addens[i])
	{
		vct->str[vct->len] = addens[i];
		vct->len++;
		i++;
	}
	vct->str[vct->len] = '\0';
	return (SUCCESS);
}

int				vct_app_nstr(t_vector *vct, char *addens, size_t n)
{
	unsigned long		i;
	size_t				expected_len;

	if (addens == NULL || vct == NULL || vct->str == NULL || n <= 0)
		return (SUCCESS);
	i = 0;
	expected_len = vct->len + n;
	if (expected_len >= vct->size)
	{
		if (vct_extend(vct, expected_len) == FAILURE)
			return (FAILURE);
	}
	while (addens[i] && i < n)
	{
		vct->str[vct->len] = addens[i];
		vct->len++;
		i++;
	}
	vct->str[vct->len] = '\0';
	return (SUCCESS);
}
