# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cristje <cristje@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 16:43:16 by cvan-sch          #+#    #+#              #
#    Updated: 2023/01/13 16:04:00 by cristje          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c split_arg.c access.c
CFLAGS	= -Wall -Werror -Wextra
NAME	= pipex

all : $(NAME)

$(NAME) : $(SRC)
	make -C libft
	@$(CC) -o $@ $^ libft/libft.a
	@echo "[COMPILED]"

clean :
	rm -f pipex

fclean : clean
	rm -f $(NAME)

re : fclean all