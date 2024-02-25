#-----------------#
#    VARIABLES    #
#-----------------#

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUDES = includes


#---------------#
#    SOURCES    #
#---------------#

# CHAR
SRC_CHAR_DIR = char
SRC_CHAR = ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isprint.c \
		   ft_isspace.c \
		   ft_tolower.c \
		   ft_toupper.c \
		   ft_isinstr.c

# CONVERSIONS
SRC_CONVERSION_DIR = conversion
SRC_CONVERSION = ft_atoi.c \
				 ft_itoa.c

# MEMORY
SRC_MEMORY_DIR = memory
SRC_MEMORY = ft_bzero.c \
			 ft_calloc.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_memset.c

# PRINT
SRC_PRINT_DIR = print
SRC_PRINT = ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c

# STR
SRC_STR_DIR = str
SRC_STR = ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_strslice.c \
		  ft_strconcat.c \
		  ft_strappend.c

# LIST
SRC_LIST_DIR = list
SRC_LIST = ft_lstadd_back.c \
		   ft_lstadd_front.c \
		   ft_lstclear.c \
		   ft_lstdelone.c \
		   ft_lstiter.c \
		   ft_lstlast.c \
		   ft_lstmap.c \
		   ft_lstnew.c \
		   ft_lstsize.c

# PRINTF
SRC_PRINTF_DIR = printf
SRC_PRINTF_PARSER = ft_parser.c \
					ft_parse_flag.c \
					ft_parse_minimum_field_width.c \
					ft_parse_precision.c \
					ft_parse_conversion_type.c

SRC_PRINTF_ELEMENT = ft_element_create_empty.c \
					 ft_element_print.c \
					 ft_element_destroy.c \
					 ft_element_print.c

SRC_PRINTF_CONVERT = ft_convert_c.c \
					 ft_convert_d.c \
					 ft_convert_i.c \
					 ft_convert_p.c \
					 ft_convert_percent.c \
					 ft_convert_s.c \
					 ft_convert_u.c \
					 ft_convert_x.c \
					 ft_convert_x_upper.c

SRC_PRINTF_HELPERS = ft_size_t_to_str_base.c \
					 ft_size_t_to_str_hex.c \
					 ft_helper_add_precision.c \
					 ft_helper_add_padding.c \
					 ft_helper_add_prefix.c

SRC_PRINTF_OUTPUT_STRING = ft_output_string_create_empty.c \
						   ft_output_string_destroy.c \
						   ft_output_string_len.c \
						   ft_output_string_print.c

SRC_PRINTF_ELEMENT_TO_OUTPUT_STRING = ft_convert_element_to_output_string.c \
									  ft_convert_element_c_to_output_string.c \
									  ft_convert_element_d_to_output_string.c \
									  ft_convert_element_i_to_output_string.c \
									  ft_convert_element_p_to_output_string.c \
									  ft_convert_element_percent_to_output_string.c \
									  ft_convert_element_s_to_output_string.c \
									  ft_convert_element_u_to_output_string.c \
									  ft_convert_element_x_to_output_string.c \
									  ft_convert_element_x_upper_to_output_string.c
SRC_PRINTF = ft_printf.c \
			 $(SRC_PRINTF_PARSER) \
			 $(SRC_PRINTF_ELEMENT) \
			 $(SRC_PRINTF_CONVERT) \
			 $(SRC_PRINTF_HELPERS) \
			 $(SRC_PRINTF_OUTPUT_STRING) \
			 $(SRC_PRINTF_ELEMENT_TO_OUTPUT_STRING) \

# GET NEXT LINE
SRC_GNL_DIR = get_next_line
SRC_GNL = get_next_line.c \
		  get_next_line_utils.c

# DLIST
SRC_DLIST_DIR = dlist
SRC_DLIST = dlist.c \
			dlist1.c \
			dlist2.c

# DEQUE
SRC_DEQUE_DIR = deque
SRC_DEQUE = deque.c \
			deque1.c

#-----------------------#
#    SRC DIRECTORIES    #
#-----------------------#

SRCS_RAW = $(addprefix $(SRC_CHAR_DIR)/, $(SRC_CHAR)) \
		   $(addprefix $(SRC_CONVERSION_DIR)/, $(SRC_CONVERSION)) \
		   $(addprefix $(SRC_MEMORY_DIR)/, $(SRC_MEMORY)) \
		   $(addprefix $(SRC_PRINT_DIR)/, $(SRC_PRINT)) \
		   $(addprefix $(SRC_STR_DIR)/, $(SRC_STR)) \
		   $(addprefix $(SRC_LIST_DIR)/, $(SRC_LIST)) \
		   $(addprefix $(SRC_PRINTF_DIR)/, $(SRC_PRINTF)) \
		   $(addprefix $(SRC_GNL_DIR)/, $(SRC_GNL)) \
		   $(addprefix $(SRC_DLIST_DIR)/, $(SRC_DLIST)) \
		   $(addprefix $(SRC_DEQUE_DIR)/, $(SRC_DEQUE))

SRC_DIR = src

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_RAW))

OBJS_RAW = $(SRCS_RAW:.c=.o)

OBJ_DIR = obj

OBJS = $(patsubst %,$(OBJ_DIR)/%, $(OBJS_RAW))

OBJ_SUBDIRS = $(SRC_CHAR_DIR) \
			  $(SRC_CONVERSION_DIR) \
			  $(SRC_MEMORY_DIR) \
			  $(SRC_PRINT_DIR) \
			  $(SRC_STR_DIR) \
			  $(SRC_LIST_DIR) \
			  $(SRC_PRINTF_DIR) \
			  $(SRC_GNL_DIR)


#-------------#
#    RULES    #
#-------------#

all: $(NAME)

bonus: all

# Explanantion of pattern flags
# Ref: https://stackoverflow.com/a/37701195
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	-rm -f $(OBJS)
	-rm -df $(patsubst %,$(OBJ_DIR)/%, $(OBJ_SUBDIRS))
	-rm -df $(OBJ_DIR)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
