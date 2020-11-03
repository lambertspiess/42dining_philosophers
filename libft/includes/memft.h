/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:48:23 by lspiess           #+#    #+#             */
/*   Updated: 2020/06/03 15:25:07 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMFT_H
# define MEMFT_H
# include <unistd.h>
# include <stdlib.h>

int				ft_free(void **p);
void			ft_frees(int nb, ...);

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);

void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);

void			ft_memdel(void **ap);

void			*ft_mmalloc(int size);
void			*ft_memalloc(size_t size);
void			*ft_malloc_memset(size_t size, char c);
void			*ft_calloc(size_t nelem, size_t elemsize);

#endif
