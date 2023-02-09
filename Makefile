# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cristje <cristje@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 16:43:16 by cvan-sch      #+#    #+#                  #
#    Updated: 2023/02/06 16:20:58 by cvan-sch      ########   odam.nl          #
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

OBJ_F = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ_F)
	@make -C libft
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	@rm -f outfile
	@rm -f $(SRC_REG:%.c=%.o)
	@rm -f $(SRC_BONUS:%.c=%.o)
	@echo "removed object/outfile"
	@make -C libft clean

fclean : clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	@echo "removed executable"

re : fclean all

bonus :
	@make WITH_BONUS=1 all

git :
	@git add .
	@git commit -m $(MSG)
	@git push
