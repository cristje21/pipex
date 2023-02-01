# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cristje <cristje@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 16:43:16 by cvan-sch      #+#    #+#                  #
#    Updated: 2023/02/01 13:52:23 by cvan-sch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC		=	main.c split_arg.c access.c pipex_utils.c paths.c
CFLAGS	=	-Wall -Werror -Wextra
NAME	=	pipex
MSG		?=	"automatic push"

all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ libft/libft.a
	@echo "completed	:	compilation		:	pipex"

clean :
	@rm -f infile
	@rm -f outfile
	@echo "removed	:	infile outfile		:	$(NAME)"
	@make -C libft clean

fclean : clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	@echo "removed	:	archive			:	libft"
	@echo "removed	:	executable		:	$(NAME)"

re : fclean all

git :
	@git add .
	@git commit -m $(MSG)
	@git push