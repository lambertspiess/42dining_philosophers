# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspiess <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 20:10:51 by lspiess           #+#    #+#              #
#    Updated: 2020/06/30 13:56:52 by lspiess          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Compiler flags
#ifdef f
#	ifeq ($(f), no)
#		CFLAGS=
#	endif
#	ifeq ($(f), v)# Valgrind flags
#		CFLAGS = -Wall -Wextra -ggdb3 -pedantic
#	endif
#	ifeq ($(f), s)# Sanitize flags
#		CFLAGS = -Wall -Wextra -fsanitize=address,undefined -pedantic
#	endif
#else
#	CFLAGS = -Wall -Wextra -Werror
#endif
#
#\033[nK => K pour effacer les n premiers caractères
#Ne rien mettre ou mettre 0 efface toute la ligne
#​
#\033[nA => A pour placer le curseur n lignes plus haut.
#Ne rien mettre ou mettre 0 laisse le curseur sur sa position actuelle

# -lft pour indique au'il y a une lib statique, et -L<libname(without .a)>
#  l'ajoute

################################################################################
##############################                 #################################
##############################    HEADERS      #################################
##############################                 #################################
################################################################################

# Headers names
HEADERSNAMES += chartft.h
HEADERSNAMES += stringft.h
HEADERSNAMES += concatft.h
HEADERSNAMES += convft.h
HEADERSNAMES += listft.h
HEADERSNAMES += mathft.h
HEADERSNAMES += memft.h
HEADERSNAMES += outft.h
HEADERSNAMES += bigint.h
HEADERSNAMES += vectorft.h
HEADERSNAMES += gnl.h
HEADERSNAMES += libft.h
HEADERSNAMES += ft_printf.h

# Headers paths
HEADERSPATH += includes

HEADERS = $(addprefix $(HEADERSPATH)/, $(HEADERSNAMES))

################################################################################
##############################                 #################################
##############################   PRINT VARS    #################################
##############################                 #################################
################################################################################

GREEN = \033[32m
CYAN = \033[0;36m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m

CLEAR = \033[0m

# Clear line
CLRLINE = \033[K

# Go back to line
BTOLINE = \033[A

################################################################################
##############################                 #################################
##############################   SRCS NAMES    #################################
##############################                 #################################
################################################################################

#--------------------------------- STRING -------------------------------------#

SRCNAMES += ft_istrlen.c
SRCNAMES += ft_strcapitalize.c
SRCNAMES += ft_strchr.c
SRCNAMES += ft_strchr_idx.c
SRCNAMES += ft_strrchr.c
SRCNAMES += ft_strcmp.c
SRCNAMES += ft_strcpy.c
SRCNAMES += ft_strdup.c
SRCNAMES += ft_strequ.c
SRCNAMES += ft_striter.c
SRCNAMES += ft_striteri.c
SRCNAMES += ft_strjoin.c
SRCNAMES += ft_strlcat.c
SRCNAMES += ft_strlen.c
SRCNAMES += ft_strmap.c
SRCNAMES += ft_strmapi.c
SRCNAMES += ft_strncmp.c
SRCNAMES += ft_strncpy.c
SRCNAMES += ft_strndup.c
SRCNAMES += ft_strnequ.c
SRCNAMES += ft_strnjoin.c
SRCNAMES += ft_strnstr.c
SRCNAMES += ft_strrev.c
SRCNAMES += ft_split_whitespace.c
SRCNAMES += ft_strstr.c
SRCNAMES += ft_substr.c
SRCNAMES += ft_strtrim.c
SRCNAMES += ft_tolower.c
SRCNAMES += ft_toupper.c
SRCNAMES += ft_strdel.c
SRCNAMES += ft_strnew.c

#--------------------------------- CHAR ---------------------------------------#

SRCNAMES += ft_isalnum.c
SRCNAMES += ft_isalpha.c
SRCNAMES += ft_isascii.c
SRCNAMES += ft_isdigit.c
SRCNAMES += ft_isprint.c

#--------------------------------- LIST ---------------------------------------#

SRCNAMES += ft_lstadd.c
SRCNAMES += ft_lstclear.c
SRCNAMES += ft_lstdelone.c
SRCNAMES += ft_lstiter.c
SRCNAMES += ft_lstmap.c
SRCNAMES += ft_lstnew.c
SRCNAMES += ft_lstlast.c
SRCNAMES += ft_lstsize.c

#------------------------------- CONVERSION -----------------------------------#

SRCNAMES += ft_atoi.c
SRCNAMES += ft_itoa.c
SRCNAMES += ft_ltoa.c
SRCNAMES += ft_lltoa.c
SRCNAMES += ft_itoa_base.c
SRCNAMES += ft_utoa.c
SRCNAMES += ft_utoa_base.c

#-------------------------------- MEMORY --------------------------------------#

SRCNAMES += ft_bzero.c
SRCNAMES += ft_free.c
SRCNAMES += ft_frees.c
SRCNAMES += ft_memccpy.c
SRCNAMES += ft_memchr.c
SRCNAMES += ft_memcmp.c
SRCNAMES += ft_memcpy.c
SRCNAMES += ft_memdel.c
SRCNAMES += ft_memmove.c
SRCNAMES += ft_memset.c
SRCNAMES += ft_mmalloc.c
SRCNAMES += ft_memalloc.c
SRCNAMES += ft_calloc.c

#-------------------------------- OUTPUT --------------------------------------#

SRCNAMES += ft_printmem.c
SRCNAMES += ft_putchar.c
SRCNAMES += ft_putchar_fd.c
SRCNAMES += ft_putendl.c
SRCNAMES += ft_putendl_fd.c
SRCNAMES += ft_putnbr.c
SRCNAMES += ft_putnbr_fd.c
SRCNAMES += ft_putstr.c
SRCNAMES += ft_putstr_fd.c

#-------------------------------- MATHS ---------------------------------------#

SRCNAMES += ft_isqrt.c
SRCNAMES += ft_nblen.c

#--------------------------------- GNL ----------------------------------------#

SRCNAMES += gnl_utils.c
SRCNAMES += gnl.c

#-------------------------------- VECTOR --------------------------------------#

SRCNAMES += vct_new.c
SRCNAMES += vct_reset.c
SRCNAMES += vct_app.c
SRCNAMES += vct_cut.c
SRCNAMES += vct_extend.c
SRCNAMES += vct_shrink.c
SRCNAMES += vct_print.c
SRCNAMES += vct_insert.c
SRCNAMES += vct_free.c
SRCNAMES += vct_dup.c

#-------------------------------- PRINTF --------------------------------------#

SRCNAMES += ft_printf.c
SRCNAMES += pf_asvct_printf.c
SRCNAMES += pf_scan_format_str.c
SRCNAMES += pf_parse_conv_substr.c
SRCNAMES += pf_build_argstr.c
SRCNAMES += pf_build_c_spec.c
SRCNAMES += pf_build_s_spec.c
SRCNAMES += pf_build_p_spec.c
SRCNAMES += pf_build_d_spec.c
SRCNAMES += pf_build_num_spec_utils.c
SRCNAMES += pf_build_u_spec.c
SRCNAMES += pf_build_x_spec.c
SRCNAMES += pf_build_percent_spec.c

################################################################################
##############################                 #################################
##############################   SRCS PATHS    #################################
##############################                 #################################
################################################################################

VPATH += .:.
VPATH +=:srcs/

################################################################################
##############################                 #################################
##############################      OBJS       #################################
##############################                 #################################
################################################################################

OBJSPATH = objects_libft
OBJSNAMES = $(SRCNAMES:.c=.o)
OBJS = $(addprefix $(OBJSPATH)/,$(OBJSNAMES))

VALOBJSPATH = vg_objects_libft
VALOBJS = $(addprefix $(VALOBJSPATH)/,$(OBJSNAMES))

SANOBJSPATH = san_objects_libft
SANOBJS = $(addprefix $(SANOBJSPATH)/,$(OBJSNAMES))

################################################################################
##############################                 #################################
##############################    MAIN VARS    #################################
##############################                 #################################
################################################################################

# Name
NAME = libft.a
SANNAME = libftsan.a
VALNAME = libftval.a

# Compiler
CC = gcc

# Compiler flags
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

# sanitize flags
SANITIZE_FLAGS += -Wall -Wextra -Werror -fsanitize=address,undefined -ggdb3# -pedantic

# valgrind flags
VALGRIND_FLAGS += -Wall -Wextra -Werror -ggdb3# -pedantic

################################################################################
##############################                 #################################
##############################      RULES      #################################
##############################                 #################################
################################################################################

#--------------------------------- STANDARD -----------------------------------#

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(CLRLINE)$(CYAN)libft.a$(CLEAR)"

$(OBJS) : $(OBJSPATH)/%.o: %.c
	@mkdir $(OBJSPATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I $(HEADERSPATH) -o $@ -c $<
	@echo "$(CYAN) Compiling libft : libft/$<$(CLEAR)$(CLRLINE)$(BTOLINE)"

clean :
	@rm -f $(OBJS) $(SANOBJS) $(VALOBJS)
	@rm -f $(SANOBJS)
	@rm -f $(VALOBJS)
	@rm -rf $(OBJSPATH) 2> /dev/null || true
	@rm -rf $(SANOBJSPATH) 2> /dev/null || true
	@rm -rf $(VALOBJSPATH) 2> /dev/null || true

fclean : clean
	@rm -f $(NAME)
	@rm -f $(SANNAME)
	@rm -f $(VALNAME)

re :
	@make fclean
	@make all

#--------------------------------- SANITIZE -----------------------------------#

san : $(SANOBJS)
	@ar rc $(SANNAME) $(SANOBJS)
	@ranlib $(SANNAME)
	@echo "$(CLRLINE)$(PURPLE)libftsan.a$(CLEAR)"

$(SANOBJS) : $(SANOBJSPATH)/%.o: %.c
	@mkdir $(SANOBJSPATH) 2> /dev/null || true
	@$(CC) $(SANITIZE_FLAGS) -I $(HEADERSPATH) -o $@ -c $<
	@echo "$(PURPLE) Compiling libftsan : libft/$<$(CLEAR)$(CLRLINE)$(BTOLINE)"

sanclean :
	@rm -f $(SANOBJS)
	@rm -rf $(SANOBJSPATH) 2> /dev/null || true

sanfclean : sanclean
	@rm -f $(SANNAME)

sanre :
	@make sanfclean
	@make san

#--------------------------------- VALGRIND -----------------------------------#

val : $(VALOBJS)
	@ar rc $(VALNAME) $(VALOBJS)
	@ranlib $(VALNAME)
	@echo "$(CLRLINE)$(YELLOW)libfval.a$(CLEAR)"

$(VALOBJS) : $(VALOBJSPATH)/%.o: %.c
	@mkdir $(VALOBJSPATH) 2> /dev/null || true
	@$(CC) $(VALGRIND_FLAGS) -I $(HEADERSPATH) -o $@ -c $<
	@echo "$(YELLOW) Compiling libftval : libft/$<$(CLEAR)$(CLRLINE)$(BTOLINE)"

valclean :
	@rm -f $(VALOBJS)
	@rm -rf $(VALOBJSPATH) 2> /dev/null || true

valfclean : valclean
	@rm -f $(VALNAME)

valre :
	@make valfclean
	@make val
#
##---------------------------------- CLEAN -------------------------------------#

cleanall :
	@rm -f $(OBJS)
	@rm -f $(VALOBJS)
	@rm -f $(SANOBJS)
	@rm -rf $(OBJSPATH) 2> /dev/null || true
	@rm -rf $(VALOBJSPATH) 2> /dev/null || true
	@rm -rf $(SANOBJSPATH) 2> /dev/null || true

fcleanall : clean sanclean valclean
	@rm -f $(NAME)
	@rm -f $(SANNAME)
	@rm -f $(VALNAME)

reall :
	@make fcleanall
	@make all
	@make $(SANNAME)

.PHONY : all, clean, fclean, re
