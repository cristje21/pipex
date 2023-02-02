# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cristje <cristje@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 16:43:16 by cvan-sch      #+#    #+#                  #
#    Updated: 2023/02/02 16:12:12 by cvan-sch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_REG		=	main.c split_arg.c access.c\
				pipex_utils.c paths.c error.c

SRC_BONUS	=	main_bonus.c split_arg_bonus.c access_bonus.c\
				pipex_utils_bonus.c here_doc_bonus.c paths_bonus.c\
				error_bonus.c

CFLAGS		=	-Wall -Werror -Wextra
NAME		=	pipex
MSG			?=	"automatic push"

ifdef WITH_BONUS
SRC = $(SRC_BONUS)
else
SRC = $(SRC_REG)
endif

all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

clean :
	@rm -f infile
	@rm -f outfile
	@echo "removed infile outfile"
	@make -C libft clean

fclean : clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	@echo "removed executable"

re : fclean all

bonus :
	make WITH_BONUS=1 all

git :
	@git add .
	@git commit -m $(MSG)
	@git push
