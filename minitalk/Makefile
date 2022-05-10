# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 18:36:46 by hyunkkim          #+#    #+#              #
#    Updated: 2022/05/10 18:24:09 by hyunkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME=minitalk
CLIENT=client
CLIENT_BONUS=client_bonus
SERVER=server
SERVER_BONUS=server_bonus
CC=cc
CFLAGS=-Wall -Werror -Wextra
LIB_NAME=ftprintf
LIB_DIR=./ft_printf/
LIB=$(LIB_DIR)lib$(LIB_NAME).a
LIBFT=libftprintf.a
INCLUDE=-I ./Libft -I ./ft_printf
RM=rm -f
CP=cp
SRC_CLIENT= client.c \
			utils.c
SRC_SERVER= server.c \
			utils.c
OBJ_CLIENT= client.o \
			utils.o
OBJ_SERVER= server.o \
			utils.o
SRC_CLIENT_BONUS= client_bonus.c \
				  utils_bonus.c
SRC_SERVER_BONUS= server_bonus.c \
				  utils_bonus.c
OBJ_CLIENT_BONUS= client_bonus.o \
				  utils_bonus.o
OBJ_SERVER_BONUS= server_bonus.o \
				  utils_bonus.o

$(NAME) : $(CLIENT) $(SERVER)

$(CLIENT) :$(LIB) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJ_CLIENT) -o $(CLIENT)

$(SERVER) :$(LIB) $(OBJ_SERVER)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT_BONUS) : $(LIB) $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJ_CLIENT_BONUS) -o $(CLIENT_BONUS)

$(SERVER_BONUS) :$(LIB) $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJ_SERVER_BONUS) -o $(SERVER_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR) all
	$(CP) $(LIB) .

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(RM) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(CLIENT) $(CLIENT_BONUS)
	$(RM) $(SERVER) $(SERVER_BONUS)
	$(RM) $(LIBFT)

re : fclean all

bonus : $(CLIENT_BONUS) $(SERVER_BONUS)

.PHONY : all clean fclean re bonus
