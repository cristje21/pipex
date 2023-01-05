# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cristje <cristje@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 16:43:16 by cvan-sch      #+#    #+#                  #
#    Updated: 2023/01/05 15:56:11 by cvan-sch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC		= main.c split_arg.c acces.c
CFLAGS	= -Wall -Werror -Wextra
NAME	= pipex

all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft all
	@$(CC) -o $@ $^ libft/libft.a
	@echo hello word

clean :
	rm -f pipex