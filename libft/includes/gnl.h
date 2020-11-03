/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:17:12 by lspiess           #+#    #+#             */
/*   Updated: 2020/07/01 10:14:29 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "stringft.h"
# include "memft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_gnl_stream {
	int						fd;
	struct s_gnl_stream		*prev;
	struct s_gnl_stream		*next;
	char					*data;
}					t_gnl_stream;

t_gnl_stream	*gnl_alloc_node(int fd);
void			gnl_free_node(t_gnl_stream **node);

int				get_next_line(char **line, int fd);

#endif
