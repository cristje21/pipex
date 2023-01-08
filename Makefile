# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cristje <cristje@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 16:43:16 by cvan-sch      #+#    #+#                  #
#    Updated: 2023/01/08 20:28:21 by cvan-sch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC		= main.c pipex_utils/split_arg.c pipex_utils/access.c
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