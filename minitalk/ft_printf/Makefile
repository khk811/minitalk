# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:13:44 by hyunkkim          #+#    #+#              #
#    Updated: 2022/05/02 14:47:06 by hyunkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
LIB_DIR=../Libft/
LIB_NAME=ft
LIB=$(LIB_DIR)lib$(LIB_NAME).a
INCLUDE=-I ../Libft
AR=ar
ARFLAGS=rcs
RM=rm -f
CP=cp
SRC= ft_printf.c \
	  ft_is.c \
	  ft_addrtoa.c \
	  ft_uns_itoa.c \
	  ft_utils_str.c \
	  ft_parce_tree.c \
	  ft_get_func.c \
	  ft_write_addr.c \
	  ft_write_char.c \
	  ft_write_digit.c \
	  ft_write_hex_lo.c \
	  ft_write_hex_up.c \
	  ft_write_percent.c \
	  ft_write_str.c \
	  ft_write_uns_int.c
OBJ=$(SRC:.c=.o)

$(NAME) : $(LIB) $(OBJ)
	$(CP) $(LIB) $(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

$(LIB) :
	make -C $(LIB_DIR) bonus

all : $(NAME)

re : fclean all

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJ)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

.PHONY: all clean fclean re
