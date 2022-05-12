# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 13:51:28 by hyunkkim          #+#    #+#              #
#    Updated: 2022/05/12 14:04:11 by hyunkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME=minitalk_bonus
CLIENT=client
SERVER=server
CC=cc
CFLAGS=-Wall -Werror -Wextra
LIB_NAME=ftprintf
LIB_DIR=../ft_printf/
LIB=$(LIB_DIR)lib$(LIB_NAME).a
INCLUDE=-I ../Libft -I ../ft_printf
RM=rm -f
SRC_CLIENT= client_bonus.c \
			utils_bonus.c
SRC_SERVER= server_bonus.c \
			utils_bonus.c
OBJ_CLIENT=$(SRC_CLIENT:%.c=%.o)
OBJ_SERVER=$(SRC_SERVER:%.c=%.o)

$(NAME) : $(CLIENT) $(SERVER)

$(CLIENT) :$(LIB) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJ_CLIENT) -o $(CLIENT)

$(SERVER) :$(LIB) $(OBJ_SERVER)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJ_SERVER) -o $(SERVER)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR) all

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(CLIENT) $(SERVER)

re : fclean all

.PHONY : all clean fclean re
