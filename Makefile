# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 21:50:54 by tday              #+#    #+#              #
#    Updated: 2024/02/03 21:50:54 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			:=		minishell
SRC_DIRS		:=		src/builtins src/main #src/(add folder names)
INC_DIR			:=		inc
LIBFT_DIR		:=		libft
LIBFT			:=		$(LIBFT_DIR)/libft.a
SRCS 			:= 		$(addprefix src/builtins/, pwd.c echo.c)				\
						$(addprefix src/main/, main.c)							\
						#$(addprefix src/(add folder names)/, (add file names))
OBJS 			:=		$(SRCS:.c=.o)
CC				:=		gcc
CFLAGS			:=		-Wall -Wextra -Werror -I$(INC_DIR)
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

$(NAME):		$(LIBFT) $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
				@echo "$(CYAN)Everything compiled and linked into executable: $(BLUE)$(NAME)$(DEFAULT_COLOUR)"
				@echo "\n"

$(LIBFT):		
				@$(MAKE) -s -C $(LIBFT_DIR)

$(OBJS):		%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(call check_dir_change,$<)

clean:			
				@$(RM) $(OBJS)
				@$(foreach dir,$(SRC_DIRS),echo "$(MAGENTA)$(notdir 			\
				$(patsubst %/,%,$(dir))) object files deleted.					\
				$(DEFAULT_COLOUR)";)

fclean: 		
				@$(MAKE) fclean -s -C $(LIBFT_DIR)
				@$(MAKE) -s clean
				@$(RM) $(NAME)
				@echo "$(YELLOW)$(NAME) deleted.$(DEFAULT_COLOUR)"
				@echo "\n"

re: 			fclean all

.PHONY: 		all clean fclean re