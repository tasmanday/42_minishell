#-----------------#
#    VARIABLES    #
#-----------------#

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
# TODO: Add header change detection
# CFLAGS = -Wall -Wextra -Werror -MD

#----------------#
#    INCLUDES    #
#----------------#

INC = inc
LIBFT_INC = libft/includes
LIBFT = libft/libft.a

INCL_RL = /usr/local/opt/readline/include/
LINK_RL = /usr/local/opt/readline/lib

#---------------#
#    SOURCES    #
#---------------#

SRC_FILES = read.c			\
	source.c				\
	source1.c				\
	source2.c				\
	source3.c				\
	lexer.c					\
	lexer1.c				\
	syntax_check.c			\
	syntax_check1.c			\
	syntax_check2.c			\
	syntax_check3.c			\
	heredoc.c				\
	heredoc1.c				\
	tilde_expansion.c		\
	parameter_expansion.c	\
	parameter_expansion1.c	\
	split.c					\
	split1.c				\
	filename_expansion.c	\
	filename_expansion1.c	\
	filename_expansion2.c	\
	quote_removal.c			\
	quote_removal1.c		\
	parse.c					\
	parse1.c				\
	parse2.c				\
	parse3.c				\
	execute.c				\
	execute1.c				\
	execute2.c				\
	execute3.c				\
	execute4.c				\
	redirection.c			\
	redirection1.c			\
	redirection2.c			\
	redirection3.c			\
	command.c				\
	command1.c				\
	path.c					\
	shlvl.c					\
	signal.c				\
	signal1.c				\
	term.c					\
	builtins/cd.c			\
	builtins/cd1.c			\
	builtins/echo.c			\
	builtins/env.c			\
	builtins/exit.c			\
	builtins/export.c		\
	builtins/export1.c		\
	builtins/export2.c		\
	builtins/getenv.c		\
	builtins/pwd.c			\
	builtins/unset.c		\
	builtins/builtin_utils.c\
	builtins/builtin_execve.c\
	repl.c 					\
	utils.c					\
	utils1.c				\
	utils2.c				\
	utils3.c				\
	debug.c 				

SRC_MAIN = main.c

SRCS_RAW = $(SRC_FILES) \
	$(SRC_MAIN)


SRC_DIR = src

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_RAW))

OBJ_DIR = obj

OBJ_RAW = $(SRCS_RAW:.c=.o)

OBJS = $(patsubst %,$(OBJ_DIR)/%, $(OBJ_RAW))

DEPENDENCY_DIR = obj

DEPENDENCY_RAW = $(SRCS_RAW:.c=.d)

DEPENDENCIES = $(patsubst %, $(DEPENDENCY_DIR)/%, $(DEPENDENCY_RAW))

#-------------#
#    RULES    #
#-------------#

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) -I $(LIBFT_INC) -L libft $(OBJS) -lft -L $(LINK_RL) -lreadline -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Making $<"
	$(CC) $(CFLAGS) -I $(INC) -I $(LIBFT_INC) -I $(INCL_RL) -c $< -o $@ -MD

$(LIBFT):
	@echo "Making libft"
	$(MAKE) -C libft

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)
	rm -f $(DEPENDENCIES)
	rm -df obj/builtins
	rm -df obj

fclean:
	$(MAKE) fclean -C libft
	rm -f $(OBJS)
	rm -f $(DEPENDENCIES)
	rm -df obj/builtins
	rm -df obj
	rm -f $(NAME)

re: fclean all
	$(MAKE) re -C libft

# Add dependencies to detect changes in header files
# Ref: https://nathandumont.com/blog/automatically-detect-changes-in-header-files-in-a
-include $(OBJS:.o=.d)

.PHONY: all libft clean fclean re
