# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:11:43 by grigaux           #+#    #+#              #
#    Updated: 2020/09/08 10:37:04 by grigaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_ROOT = ./libft

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
INCFLAGS = -I$(LIBFT_ROOT)

RM = rm -f
LIB = ar rcs
MAKE = make

NAME = libftprintf.a
SRC = c_conversion.c ft_printf.c i_conversion.c p_conversion.c s_conversion.c \
	  t_x_conversion.c u_conversion.c u_x_conversion.c other_functions.c ft_utoa.c \
	  ft_tiny_xtoa.c ft_upper_xtoa.c ft_ptoa.c ft_percent_convers.c x_conv.c iu_conv.c \
	  sp_conv.c ft_c_handler.c ft_flags_handler.c i_conversion2.c u_conversion2.c \
	  x_conv2.c

OBJ = $(SRC:.c=.o)
	INCLUDE = ft_printf.h

all: libft_all $(NAME)

$(NAME): $(OBJ)
		cp $(LIBFT_ROOT)/libft.a $(NAME)
			$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
		$(CC) $(CCFLAGS) $(INCFLAGS) -c -o $@ $<

bonus: all

clean: libft_clean
		$(RM) $(OBJ)

fclean: libft_fclean clean
		$(RM) $(NAME)

re: fclean all

libft_all:
		$(MAKE) -C $(LIBFT_ROOT) all

libft_bonus:
		$(MAKE) -C $(LIBFT_ROOT) bonus

libft_clean:
		$(MAKE) -C $(LIBFT_ROOT) clean

libft_fclean:
		$(MAKE) -C $(LIBFT_ROOT) fclean

.PHONY:		all clean fclean re