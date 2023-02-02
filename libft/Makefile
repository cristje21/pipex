# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cristje <cristje@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/12 13:59:30 by cvan-sch      #+#    #+#                  #
#    Updated: 2023/02/02 16:04:55 by cvan-sch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

SRC_F = ft_isalpha.c ft_isdigit.c ft_isalnum.c\
		ft_isascii.c ft_isprint.c ft_strlen.c\
		ft_memset.c ft_bzero.c ft_memcpy.c\
		ft_memmove.c ft_strlcpy.c ft_strlcat.c\
		ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strncmp.c ft_memchr.c ft_memcmp.c\
		ft_strnstr.c ft_atoi.c ft_calloc.c\
		ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_itoa.c ft_strmapi.c\
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_split.c\
		ft_strrchr.c ft_lstnew.c ft_lstadd_front.c\
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
		get_next_line.c get_next_line_utils.c\
		ft_printf.c ft_put_two.c ft_put.c\
		ft_print_array.c ft_putnstr_fd.c

NAME = libft.a
OBJ_F = $(SRC_F:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ_F)
	@ar rc $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	@rm -f $(OBJ_F)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
