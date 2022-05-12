# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 18:36:46 by hyunkkim          #+#    #+#              #
#    Updated: 2022/05/12 14:00:29 by hyunkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME=minitalk
MANDATORY_DIR=./src
BONUS_DIR=./src_bonus

$(NAME) :
	make -C $(MANDATORY_DIR) all

all : $(NAME)

clean :
	make -C $(MANDATORY_DIR) clean
	make -C $(BONUS_DIR) clean

fclean :
	make -C $(MANDATORY_DIR) fclean
	make -C $(BONUS_DIR) fclean

re : fclean all

bonus :
	make -C $(BONUS_DIR) all

.PHONY : all clean fclean re bonus
