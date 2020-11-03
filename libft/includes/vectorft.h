/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:50:26 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:50:28 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORFT_H
# define VECTORFT_H

# include "libft.h"
# include <limits.h>
# define VCT_DEFSIZE		64
# define VCT_DEFQUART		16

typedef struct		s_vector {
	char			*str;
	size_t			len;
	size_t			size;
	size_t			quart;
}					t_vector;

t_vector			*vct_new(size_t size);
t_vector			*vct_reset(t_vector *vct, size_t size);

int					vct_app_char(t_vector *vct, char c);
int					vct_app_str(t_vector *vct, char *addens);
int					vct_app_nstr(t_vector *vct, char *addens, size_t n);

int					vct_extend(t_vector *vct, size_t expected_len);
int					vct_shrink(t_vector *vct);

int					vct_print(t_vector *vct);
int					vct_printnl(t_vector *vct);
int					vct_printfd(t_vector *vct, int fd);
int					vct_printnlfd(t_vector *vct, int fd);

int					vct_cut(t_vector *vct);
int					vct_cutfrom(t_vector *vct, size_t idx);
int					vct_cutnfrom(t_vector *vct, size_t idx, size_t n);

int					vct_insert_str(t_vector *vct, size_t idx, char *str);
int					vct_insert_nchar(t_vector *vct, size_t idx, char c, int n);
int					vct_insert_nstr(t_vector *vct, size_t idx, char *s, int n);
int					vct_insert_nvct(t_vector *vct, size_t idx, t_vector *app,
									int n);

void				vct_free(t_vector **vctp);

t_vector			*vct_dup(t_vector *vct);

#endif
