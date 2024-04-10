# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 21:50:54 by tday              #+#    #+#              #
#    Updated: 2024/04/07 18:34:00 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			:=		minishell
SRC_DIRS		:=		src/builtins src/main src/initialisation src/envvar		\
						src/get_input src/signals src/lexer src/parse 			\
						src/execute src/clean_up
INC_DIR			:=		inc
LIBFT_DIR		:=		libft
LIBFT			:=		$(LIBFT_DIR)/libft.a
INCL_RL 		:=		/usr/local/opt/readline/include/
LINK_RL			:=		/usr/local/opt/readline/lib
SRCS 			:= 		$(addprefix src/builtins/, pwd.c echo.c env.c export.c	\
									unset.c cd.c exit.c)						\
						$(addprefix src/main/, main.c)							\
						$(addprefix src/initialisation/, init_minishell.c		\
									clone_envv_to_dlist.c)						\
						$(addprefix src/envvar/, find_envvar_node.c 			\
									expand_envvar.c get_env_key.c				\
									get_env_value.c update_node_value.c)		\
						$(addprefix src/get_input/, get_input.c)				\
						$(addprefix src/signals/, signals.c)					\
						$(addprefix src/lexer/, add_tokens_to_list.c			\
									safe_new_token_node.c)						\
						$(addprefix src/parse/, extract_commands.c 				\
									process_input.c process_fds.c 				\
									handle_redirection.c)						\
						$(addprefix src/execute/, put_args_in_array.c 			\
									convert_envvar_to_array.c execute_builtin.c \
									cmd_is_builtin.c execute_commands.c 		\
									execute_parent.c execute_child.c cmd_path.c)\
						$(addprefix src/clean_up/, free_envv_struct.c			\
									free_data.c free_everything.c				\
									clean_exit.c free_cloned_list.c 			\
									free_cmd_struct.c msh_error_exit.c 			\
									free_tokens.c free_input.c)					
OBJS 			:=		$(SRCS:.c=.o)
CC				:=		gcc
CFLAGS			:=		-Wall -Wextra -Werror -I$(INC_DIR) -I$(INCL_RL) -g
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
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(LINK_RL) -lreadline -o $(NAME)
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
