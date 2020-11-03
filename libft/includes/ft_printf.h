/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:48:29 by lspiess           #+#    #+#             */
/*   Updated: 2020/05/23 04:06:53 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
******************************** INCLUDES **************************************
*/

# include <stdio.h>

# include "vectorft.h"
# include "stringft.h"
# include "memft.h"
# include "convft.h"
# include "charft.h"

/*
******************************** DEFINES ***************************************
*/

# define UNUSED(p)				((void)(p))

# define CONV_SPEC				"cspdiuxX%"
# define PF_FLAGS				"#-+0 *."
# define PF_FLAGS_DEFAULT		-1

# define ISMINUS				(1 << 0)
# define ISPLUS					(1 << 1)
# define ISSPACE				(1 << 2)
# define ISZERO					(1 << 3)
# define ISDOT					(1 << 4)
# define ISWILD					(1 << 5)
# define ISLONG					(1 << 6)
# define ISLONGLONG				(1 << 7)
# define ISOCT					(1 << 8)
# define ISMAJ					(1 << 9)

/*
********************************** ENUMS ***************************************
*/

typedef enum		e_state {
	RESTING, SCANNING_FORMAT_STR, PARSING_CONV_SUBSTR, BUILDING_ARGSTR, END,
}					t_state;

typedef enum		e_event {
	START, METCONV, METEND, CONV_PARSED, ARGSTR_BUILT, EXIT, ANY
}					t_event;

/*
********************************* STRUCTS **************************************
*/

typedef struct		s_stroke {
	t_state			curstate;
	t_event			lastevent;
}					t_stroke;

typedef struct		s_pf_fmt {
	char			*s;
	int				idx;
	size_t			len;
}					t_pf_fmt;

typedef struct		s_flags {
	int				widval;
	int				precval;
	unsigned int	mask;
}					t_flags;

typedef struct		s_pfengine {
	t_state			state;
	t_event			event;
	t_stroke		(*pf_run)(t_pf_fmt *fmt, t_vector *vct,
								t_flags *flags, va_list ap);
}					t_pfengine;

typedef struct		s_pf_spec_handler {
	char			spec;
	t_vector		*(*pf_build_spec)(t_flags *flags, va_list ap);
}					t_pf_spec_handler;

/*
******************************** FT_PRINTF *************************************
*/

int					ft_printf(const char *restrict format, ...);
int					ft_printf_fd(int fd, const char *restrict format, ...);
t_vector			*vct_printf(const char *restrict format, ...);
t_vector			*pf_asvct_printf(const char *restrict format, va_list ap);

/*
**************************** SCANNING_FORMAT_STR *******************************
*/

t_stroke			pf_scan_format_str(t_pf_fmt *fmt, t_vector *vct,
										t_flags *flags, va_list ap);

/*
******************************** PARSECONV *************************************
*/

t_stroke			pf_parse_conv_substr(t_pf_fmt *fmt, t_vector *vct,
											t_flags *flags, va_list ap);

/*
***************************** BUILDING_ARGSTR **********************************
*/

t_stroke			pf_build_argstr(t_pf_fmt *fmt, t_vector *vct,
										t_flags *flags, va_list ap);
t_vector			*pf_build_c_spec(t_flags *flags, va_list ap);
t_vector			*pf_build_s_spec(t_flags *flags, va_list ap);
t_vector			*pf_build_p_spec(t_flags *flags, va_list ap);
t_vector			*pf_build_d_spec(t_flags *flags, va_list ap);
t_vector			*pf_build_u_spec(t_flags *flags, va_list ap);
t_vector			*pf_build_x_spec(t_flags *flags, va_list ap);
t_vector			*pf_build_percent_spec(t_flags *flags, va_list ap);

/*
** numeric spec handlers utils
*/

void				pf_build_num_spec_precision(t_vector *app, t_flags *flags,
													char *arg_str);
void				pf_build_num_spec_width(t_vector *app, t_flags *flags);

#endif
