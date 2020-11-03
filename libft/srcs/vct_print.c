/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:19:31 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/04 19:19:50 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

int					vct_print(t_vector *vct)
{
	return (write(STDOUT_FILENO, vct->str, (int)(vct->len)));
}

int					vct_printnl(t_vector *vct)
{
	int ret;

	ret = write(STDOUT_FILENO, vct->str, (int)(vct->len));
	write(1, "\n", 1);
	return (ret);
}

int					vct_printfd(t_vector *vct, int fd)
{
	return (write(fd, vct->str, (int)(vct->len)));
}

int					vct_printnlfd(t_vector *vct, int fd)
{
	int ret;

	ret = write(STDOUT_FILENO, vct->str, (int)(vct->len));
	write(fd, "\n", 1);
	return (ret);
}
