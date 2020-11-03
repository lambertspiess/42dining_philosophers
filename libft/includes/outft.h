/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:50:21 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:50:22 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTFT_H
# define OUTFT_H
# include <unistd.h>

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);

void			ft_putstr(const char *s);
void			ft_putstr_fd(char const *s, int fd);

int				ft_nblen(int i);

void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);

void			ft_printmem(void *data, size_t data_size, int endianess);

#endif
