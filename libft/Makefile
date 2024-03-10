# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:33:08 by tday              #+#    #+#              #
#    Updated: 2024/03/10 14:27:39 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			:=		libft.a
SRC_DIRS		:=		src/array src/character src/conversion src/ft_printf	\
						src/linked_list src/math src/memory src/put src/string	\
						src/utils src/double_linked_list
INC_DIR			:=		inc
SRCS 			:= 		$(addprefix src/array/, free_array.c reverse_char_arr.c	\
									reverse_int_arr.c reverse_str_arr.c)		\
						$(addprefix src/character/, ft_isalnum.c ft_isalpha.c	\
									ft_isascii.c ft_isdigit.c ft_isprint.c		\
									ft_isspace.c ft_tolower.c ft_toupper.c)		\
						$(addprefix src/conversion/, ft_atoi.c ft_itoa.c)		\
						$(addprefix src/ft_printf/, ft_character.c ft_pointer.c	\
									ft_decimal_integer.c ft_hexadecimal.c		\
									ft_printf.c ft_string.c 					\
									ft_unsigned_integer.c)						\
						$(addprefix src/linked_list/, lst_add_head.c			\
									lst_add_tail.c lst_del_all.c lst_del_head.c	\
									lst_del_node.c lst_del_tail.c				\
									lst_get_prev.c lst_has_node.c				\
									lst_insert_after.c lst_last_node.c			\
									lst_new_node.c lst_size.c)					\
						$(addprefix src/math/, ft_abs.c ft_fabs.c ft_power.c	\
									ft_get_len_int.c ft_is_even.c ft_is_odd.c	\
									ft_remainder.c ft_round.c ft_roundf.c		\
									ft_sqrt.c)									\
						$(addprefix src/memory/, free_null.c ft_bzero.c			\
									ft_calloc.c ft_memchr.c ft_memcmp.c			\
									ft_memcpy.c ft_memmove.c ft_memset.c		\
									ft_realloc.c safe_malloc.c safe_calloc.c)	\
						$(addprefix src/put/, ft_putchar_fd.c ft_putchar.c		\
									ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c	\
									ft_putstr_fd.c ft_putstr.c)					\
						$(addprefix src/string/, ft_split.c ft_strcat.c			\
									ft_strchr.c ft_strcmp.c ft_strcpy.c			\
									ft_strdup.c ft_striteri.c ft_strjoin.c		\
									ft_strlcat.c ft_strlcpy.c ft_strlen.c		\
									ft_strmapi.c ft_strncmp.c ft_strnstr.c		\
									ft_strrchr.c ft_strstr.c ft_strtrim.c		\
									ft_substr.c get_next_line.c 				\
									ft_split_first.c ft_replace_substr.c)		\
						$(addprefix src/utils/, error_exit.c no_op.c			\
									error.c debug.c debug_int.c)				\
						$(addprefix src/double_linked_list/, dlst_add_head.c	\
									dlst_add_tail.c dlst_del_all.c 				\
									dlst_del_head.c	dlst_del_node.c 			\
									dlst_del_tail.c	dlst_has_node.c				\
									dlst_insert_after.c dlst_last_node.c		\
									dlst_new_node.c dlst_size.c 				\
									dlst_swap_nodes.c)
OBJS 			:=		$(SRCS:.c=.o)
CC				:=		cc
CFLAGS			:=		-Wall -Wextra -Werror -I$(INC_DIR)
AR				:=		ar -rcs
RM				:=		rm -f

# Function definition
define check_dir_change
$(eval CUR_DIR := $(patsubst src/%/,%, $(dir $(1))))
$(if $(filter-out $(LAST_DIR),$(CUR_DIR)), @echo 								\
"$(GREEN)$(CUR_DIR) functions compiled successfully!$(DEFAULT_COLOUR)")
$(eval LAST_DIR := $(CUR_DIR))
endef

# Colours

DEFAULT_COLOUR	:=		\033[0m
GRAY			:=		\033[1;30m
RED				:=		\033[1;31m
GREEN			:=		\033[1;32m
YELLOW			:=		\033[1;33m
BLUE			:=		\033[1;34m
MAGENTA			:=		\033[1;35m
CYAN			:=		\033[1;36m
WHITE			:=		\033[1;37m

# Recipes

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(AR) $(NAME) $(OBJS)
				@echo "$(CYAN)$(NAME) compiled successfully!$(DEFAULT_COLOUR)"
				@echo "\n"

$(OBJS):		%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(call check_dir_change,$<)

clean:
				@echo "\n"
				@$(RM) $(OBJS)
				@$(foreach dir,$(SRC_DIRS),echo "$(MAGENTA)$(notdir 			\
				$(patsubst %/,%,$(dir))) object files deleted.					\
				$(DEFAULT_COLOUR)";)

aclean: 		
				@$(RM) $(NAME)
				@echo "$(YELLOW)$(NAME) deleted.$(DEFAULT_COLOUR)"
				@echo "\n"

fclean: 		clean aclean

re: 			fclean all

.PHONY: 		all clean aclean fclean re