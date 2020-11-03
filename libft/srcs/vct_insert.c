/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:20:12 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:20:48 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

int				vct_insert_str(t_vector *vct, size_t idx, char *str)
{
	size_t			slen;
	size_t			expected_len;

	if (vct == NULL || vct->str == NULL || idx > vct->size)
		return (FAILURE);
	slen = ft_strlen(str);
	expected_len = vct->len + slen;
	if (expected_len >= vct->size)
	{
		if (vct_extend(vct, expected_len) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + idx + slen, vct->str + idx, vct->len - idx);
	ft_memcpy(vct->str + idx, str, slen);
	vct->len += slen;
	return (SUCCESS);
}

int				vct_insert_nchar(t_vector *vct, size_t idx, char c, int n)
{
	size_t			slen;
	size_t			expected_len;

	if (vct == NULL || vct->str == NULL || idx > vct->size)
		return (FAILURE);
	slen = n;
	expected_len = vct->len + n;
	if (expected_len >= vct->size)
	{
		if (vct_extend(vct, expected_len) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + idx + slen, vct->str + idx, vct->len - idx);
	while (n > 0)
	{
		vct->str[idx] = c;
		idx++;
		n--;
	}
	vct->len += slen;
	return (SUCCESS);
}

int				vct_insert_nstr(t_vector *vct, size_t idx, char *str, int n)
{
	size_t			slen;
	size_t			expected_len;

	if (vct == NULL || vct->str == NULL || idx > vct->size)
		return (FAILURE);
	slen = ft_strlen(str);
	if (n > (int)slen)
		n = slen;
	expected_len = vct->len + n;
	if (expected_len >= vct->size)
	{
		if (vct_extend(vct, expected_len) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + idx + n, vct->str + idx, vct->len - idx);
	ft_memcpy(vct->str + idx, str, n);
	vct->len += slen;
	return (SUCCESS);
}

int				vct_insert_nvct(t_vector *vct, size_t idx, t_vector *app,
								int n)
{
	size_t			expected_len;

	if (vct == NULL || vct->str == NULL || idx > vct->size)
		return (FAILURE);
	if (n > (int)(app->len))
		n = app->len;
	expected_len = vct->len + app->len;
	if (expected_len >= vct->size)
	{
		if (vct_extend(vct, expected_len) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + idx + n, vct->str + idx, vct->len - idx);
	ft_memcpy(vct->str + idx, app->str, n);
	vct->len += n;
	return (SUCCESS);
}
