/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:50:58 by tday              #+#    #+#             */
/*   Updated: 2024/03/10 14:32:06 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** libraries
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

/*
** text colours
*/

# define DEF	"\033[0m"
# define GRAY	"\033[1;30m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define MGNTA	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[1;37m"

/*
** exit values
*/

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

/*
** structs
*/

/* singularly linked list */
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

/* doubly linked list */
typedef struct s_dlist
{
	void			*data;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

/*
** prototypes
*/

/* characters */

bool		ft_isalpha(int c);
bool		ft_isdigit(int c);
bool		ft_isalnum(int c);
bool		ft_isascii(int c);
bool		ft_isprint(int c);
bool		ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/* put */

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);

/* ft_printf */

void		ft_character(char c, int *length);
void		ft_string(char *s, int *length);
void		ft_decimal_integer(int d, int *length);
void		ft_unsigned_integer(unsigned int u, int *length);
void		ft_hexidecimal(unsigned int x, int *length, char char_case,
				int first);
void		ft_pointer(size_t p, int *length, int first);
int			ft_printf(const char *string, ...);

/* memory */

void		*ft_memset(void *pointer, int c, size_t n);
void		ft_bzero(void *pointer, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *ptr, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t number, size_t size);
void		*ft_realloc(void *pointer, size_t orig_size, size_t new_size);
void		free_null(void **mem_ptr);
void		*safe_malloc(size_t bytes, char *error_message);
void		*safe_calloc(size_t number, size_t size, char *error_message);

/* conversion */

long long	ft_atoi(const char *str);
char		*ft_itoa(long long n);

/* math */

long long	ft_abs(long long n);
long double	ft_fabs(long double n);
bool		ft_is_even(long long n);
bool		ft_is_odd(long long n);
long long	ft_power(long long n, long long power);
long long	ft_sqrt(long long n);
long double	ft_remainder(long double numerator, long double denominator);
long long	ft_round(long double n);
long double	ft_roundf(long double n, int decimal_places);
size_t		ft_get_len_int(long long n);

/* strings */

size_t		ft_strlen(const char *string);
char		*ft_strcpy(char *dest, char *src);
size_t		ft_strlcpy(char *dest, const char *src, size_t dest_len);
char		*ft_strcat(char *dest, char *src);
size_t		ft_strlcat(char *dest, const char *src, size_t dest_buff_len);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strstr(char *str, char *to_find);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char *src);
char		*ft_substr(char const *str, size_t start, size_t length);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *input_str, char delimiter);
char		**ft_split_first(const char *input_str, char delimiter);
char		*ft_strmapi(const char *str, char (*f)(size_t, char));
void		ft_striteri(char *str, void (*f)(size_t, char *));
void		ft_replace_substr(char **str, int start, int end, char *substr);
char		*get_next_line(int fd);

/* arrays */

void		free_array(void **arr_ptr);
void		reverse_int_arr(int *arr, int size);
void		reverse_char_arr(char *arr, int size);
void		reverse_str_arr(char **arr, int size);

/* utils */

void		error(const char *error);
void		error_exit(const char *error);
void		no_op(void *arg);
void		debug(const char *str);
void		debug_int(int num);

/* singularly linked lists */

t_list		*lst_new_node(void *data);
void		lst_add_head(t_list **lst_head, t_list *new_node);
void		lst_add_tail(t_list **lst_head, t_list *new_node);
void		lst_insert_after(t_list *original_node, t_list *node_to_insert);
int			lst_size(t_list *lst);
t_list		*lst_last_node(t_list *lst_head);
t_list		*lst_get_prev(t_list *lst_head, t_list *curr);
bool		lst_has_node(t_list *lst_head, t_list *node_to_find);
void		lst_del_node(t_list **lst_head, t_list *node_to_del, \
			void (*ft_del)(void*));
void		lst_del_head(t_list **lst_head, void (*ft_del)(void*));
void		lst_del_tail(t_list **lst_head, void (*ft_del)(void*));
void		lst_del_all(t_list **lst_head, void (*ft_del)(void*));

/* doubly linked lists */

t_dlist		*dlst_new_node(void *data);
void		dlst_add_head(t_dlist **dlst_head, t_dlist *new_node);
void		dlst_add_tail(t_dlist **dlst_head, t_dlist *new_node);
void		dlst_insert_after(t_dlist *original_node, t_dlist *node_to_insert);
t_dlist		*dlst_last_node(t_dlist *dlst_head);
int			dlst_size(t_dlist *dlst);
bool		dlst_has_node(t_dlist *dlst_head, t_dlist *node_to_find);
void		dlst_swap_nodes(t_dlist **head, t_dlist *node1, t_dlist *node2);
void		dlst_del_node(t_dlist **dlst_head, t_dlist *node_to_del, \
			void (*ft_del)(void*));
void		dlst_del_head(t_dlist **dlst_head, void (*ft_del)(void*));
void		dlst_del_tail(t_dlist **dlst_head, void (*ft_del)(void*));
void		dlst_del_all(t_dlist **dlst_head, void (*ft_del)(void*));

#endif