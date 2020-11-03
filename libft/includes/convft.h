/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:48:04 by lspiess           #+#    #+#             */
/*   Updated: 2019/11/15 21:48:05 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVFT_H
# define CONVFT_H
# include <stdlib.h>
# include "memft.h"
# include "stringft.h"

int				ft_atoi(const char *str);

unsigned int	ft_get_nbr_size(unsigned int nb);
unsigned int	ft_get_lnbr_size(unsigned long nb);
unsigned int	ft_get_llnbr_size(unsigned long long nb);

char			*ft_itoa(int n);
char			*ft_ltoa(long n);
char			*ft_lltoa(long long n);

char			*ft_itoa_base(int n, int base);
char			*ft_ltoa_base(long n, int base);
char			*ft_lltoa_base(long long n, int base);

char			*ft_utoa(unsigned int n);
char			*ft_ultoa(unsigned long n);
char			*ft_ulltoa(unsigned long long n);

char			*ft_utoa_base(unsigned int n, int base);
char			*ft_ultoa_base(unsigned long n, int base);
char			*ft_ulltoa_base(unsigned long long n, int base);

#endif
