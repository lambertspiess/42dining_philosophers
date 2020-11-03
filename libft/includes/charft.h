/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:47:51 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:47:52 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARFT_H
# define CHARFT_H
# include <unistd.h>

int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);

#endif
