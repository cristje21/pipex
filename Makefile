# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cristje <cristje@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 16:43:16 by cvan-sch          #+#    #+#              #
#    Updated: 2023/02/02 09:32:43 by cristje          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main_bonus.c split_arg_bonus.c access_bonus.c\
			pipex_utils_bonus.c here_doc_bonus.c paths_bonus.c\
			error_bonus.c
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