# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cristje <cristje@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 16:43:16 by cvan-sch      #+#    #+#                  #
#    Updated: 2023/01/02 18:55:37 by cvan-sch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC		= main.c split_arg.c
CFLAGS	= -Wall -Werror -Wextra
NAME	= pipex

all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft all
	@$(CC) -o $@ $^ libft/libft.a
	@echo hello

clean :
	rm -f pipex