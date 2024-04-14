/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:18:52 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 15:59:08 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	ft_format_specifier
	specifies what type of argument needs to be printed and passes it to the
	correct function to be printed.

	va_arg(*args, Type)
	va_arg retrieves the next value from va_list 'args' of the type 'Type'
	depending on the format specifier Type might be char *, int, etc.

	for ft_pointer & ft_hexidecimal, first is set to 1 within
	ft_format_specifier due to the recursive nature of these functions first
	needs to begin as '1' (true) and it is then change to '0' (false) within
	the functions after the first itteration.

	if the format specifier is '%' it prints a '%' because this is the indictor
	for the format specifier and would be skipped over in ft_printf.
	in order to print it '%%' is needed.

	if the format specifier is not recognised *i is decremented, this is
	because the format specifier would not normally be printed in ft_printf and
	*i is incremented to acheive this. so in order to print the character after
	'%' *i needs to be decremented.

	Inputs
	[t_param] dumb: a struct containing the file descriptor and the format
		specifier.
	[va_list] args: a va_list pointer containing the list of arguments.
	[int *] length: a pointer to the length counter.
	[int *] i: a pointer to the index counter.

	Outputs
	none.
 */
static void	ft_format_specifier(t_param dumb, va_list *args, int *length, \
	int *i)
{
	if (dumb.fs == 'c')
		ft_character_fd(dumb.fd, va_arg(*args, int), length);
	else if (dumb.fs == 's')
		ft_string_fd(dumb.fd, va_arg(*args, char *), length);
	else if (dumb.fs == 'p')
		ft_pointer_fd(dumb.fd, va_arg(*args, size_t), length, 1);
	else if (dumb.fs == 'd' || dumb.fs == 'i')
		ft_decimal_integer_fd(dumb.fd, va_arg(*args, int), length);
	else if (dumb.fs == 'u')
		ft_unsigned_integer_fd(dumb.fd, va_arg(*args, unsigned int), length);
	else if (dumb.fs == 'x')
		ft_hexadecimal_fd(dumb.fd, va_arg(*args, unsigned int), length, 'x');
	else if (dumb.fs == 'X')
		ft_hexadecimal_fd(dumb.fd, va_arg(*args, unsigned int), length, 'X');
	else if (dumb.fs == '%')
		ft_character_fd(dumb.fd, '%', length);
	else
		(*i)--;
}

/*
	see comment below, had to separate due to norm
*/
static void	process_format_string(const char *string, t_param *dumb, \
	va_list *args, int *length)
{
	int		i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			dumb->fs = string[i];
			ft_format_specifier(*dumb, args, length, &i);
			i++;
		}
		else
		{
			ft_character_fd(dumb->fd, string[i], length);
			i++;
		}
	}
}

/*
	Summary
	ft_printf
	prints a variable number and type of arguments (...) to the given file
	descriptor.

	va_list	args; 
	this declares a 'va_list' type variable called 'args'
	a va_list is a list of arguments of no specified length that can be any
	type and can be different from one another

	va_start(args, string); 
	va_start initialises args for optional argument 
	retreval. this allows additional arguments to be passed to the function.
	string is the last know fixed parameter, any argument after string in the
	function call is stored in the va_list 'args'

	if (string[i] == '%')
	the '%' character indicates that a function specifier will follow
	it itterates to the next character with i++ then calls ft_format_specifier

	else
	if the character pointed to with string[i] is not '%' it just prints it
	using ft_character which also increases the value at &length

	va_end(args);
	cleans up the memory assigned to 'args'

	return (length);
	ft_printf returns 'length' which is the total number of characters printed
	to the output
	length is passed to, and incremented within multiple different functions
	within ft_printf

	Inputs
	[int] fd: file desciptor to output to.
	[const char *] string: the format string that specifies the desired output
		format.
	... = variable number of arguments that correspond to the format specifiers
	in the format string.

	Outputs
	[int] length: the total number of characters printed to the standard output.
*/
int	ft_printf_fd(int fd, const char *string, ...)
{
	va_list	args;
	int		length;
	t_param	dumb;

	length = 0;
	dumb.fd = fd;
	va_start(args, string);
	process_format_string(string, &dumb, &args, &length);
	va_end(args);
	return (length);
}
