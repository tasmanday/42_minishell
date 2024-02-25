/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:23 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 16:20:37 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdarg.h>

typedef enum e_flags
{
	zero_padding = 1,
	negative_field_width = 2,
	alternate_form = 4,
	prepend_negative_or_space = 8,
	prepend_sign = 16,
	precision_is_set = 32,
}	t_flags;

typedef struct s_element
{
	t_flags	flags;
	char	conversion_type;
	size_t	precision;
	size_t	minimum_field_width;
	char	*content_string;
}	t_element;

typedef struct s_output_string
{
	char	*left_padding;
	char	*prefix;
	char	*leading_zeros;
	char	*value;
	size_t	value_override_bytes_to_print;
	char	*right_padding;
}	t_output_string;

int				ft_printf(const char *format, ...);

t_element		*ft_parser(const char *format, size_t *i, va_list arg_list);
int				ft_parse_flag(const char *format, size_t *i, t_element *elem);
int				ft_parse_minimum_field_width(const char *format, size_t *i, \
t_element *element);
int				ft_parse_precision(const char *format, size_t *i, \
t_element *element);
int				ft_parse_conversion_type(const char *format, size_t *i, \
t_element *element, va_list arg_list);

t_element		*ft_element_create_empty(void);
void			ft_element_destroy(t_element *element);
size_t			ft_element_print(t_element *element);

char			*ft_convert_c(char c);
char			*ft_convert_d(int n);
char			*ft_convert_i(int n);
char			*ft_convert_p(void *ptr);
char			*ft_convert_percent(void);
char			*ft_convert_s(char *str);
char			*ft_convert_u(unsigned int num);
char			*ft_convert_x(int num);
char			*ft_convert_x_upper(int num);

char			*ft_size_t_to_str_base(size_t num, char *radix);
char			*ft_size_t_to_str_hex(size_t num);

t_output_string	*ft_output_string_create_empty(void);
void			ft_output_string_destroy(t_output_string *os);
size_t			ft_output_string_len(t_output_string *os);
size_t			ft_output_string_print(t_output_string *os);

t_output_string	*ft_convert_element_to_output_string(t_element *element);
t_output_string	*ft_convert_element_c_to_output_string(t_element *element);
t_output_string	*ft_convert_element_d_to_output_string(t_element *element);
t_output_string	*ft_convert_element_i_to_output_string(t_element *element);
t_output_string	*ft_convert_element_p_to_output_string(t_element *element);
t_output_string	*ft_convert_element_percent_to_output_string(t_element *elem);
t_output_string	*ft_convert_element_s_to_output_string(t_element *element);
t_output_string	*ft_convert_element_u_to_output_string(t_element *element);
t_output_string	*ft_convert_element_x_to_output_string(t_element *element);
t_output_string	*ft_convert_element_x_upper_to_output_string(t_element *elem);

int				ft_helper_add_precision(t_element *elem, t_output_string *os);
int				ft_helper_add_padding(t_element *element, t_output_string *os);
int				ft_helper_add_prefix(t_element *element, t_output_string *os);

#endif