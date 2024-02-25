# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 18:58:09 by wmakaran          #+#    #+#              #
#    Updated: 2023/08/15 17:37:13 by wmakaran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = \
	ft_cmd_path.c		\
	ft_error.c			\
	ft_execute.c		\
	ft_free_strs.c		\
	ft_n_putchar.c		\
	ft_n_puthex.c		\
	ft_n_putnbr.c		\
	ft_n_putpointer.c	\
	ft_n_putstr.c		\
	ft_printf.c			\
	ft_split.c			\
	ft_strchr.c			\
	ft_strjoin.c		\
	ft_strlen.c			\
	ft_strncmp.c		\
	ft_substr.c			\
	pipex.c

OBJ = $(SRC:.c=.o)

$(NAME):
	cc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: re

debug:
	cc -g -Wall -Wextra -Werror -o $(NAME) $(SRC)

.PHONY: $(NAME) clean fclean re all debug
