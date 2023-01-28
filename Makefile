# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cristje <cristje@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 16:43:16 by cvan-sch      #+#    #+#                  #
#    Updated: 2023/01/28 23:02:09 by cvan-sch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC		= main.c split_arg.c access.c pipex_utils.c
CFLAGS	= -Wall -Werror -Wextra
NAME	= pipex
MSG		?= "automatic push"

all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ libft/libft.a
	@echo "completed compilation"

clean :
	@rm -f input
	@rm -f output
	@echo "removed in and out files"

fclean : clean
	rm -f $(NAME)
	@echo "removed executable"

re : fclean all

git :
	@git add .
	@git commit -m $(MSG)
	@git push