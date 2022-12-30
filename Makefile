# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cvan-sch <cvan-sch@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 16:43:16 by cvan-sch      #+#    #+#                  #
#    Updated: 2022/12/30 18:50:05 by cvan-sch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC		= main.c
CFLAGS	= -Wall -Werror -Wextra
NAME	= pipex

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f pipex