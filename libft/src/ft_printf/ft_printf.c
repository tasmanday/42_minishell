/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:17:11 by tday              #+#    #+#             */
/*   Updated: 2024/01/15 00:17:11 by tday             ###   ########.fr       */
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

	for ft_pointer & ft_hexidecimal, first is set to 1 within ft_format_specifier
	due to the recursive nature of these functions first needs to begin as '1'
	(true) and it is then change to '0' (false) within the functions after the
	first itteration.

	if the format specifier is '%' it prints a '%' because this is the indictor
	for the format specifier and would be skipped over in ft_printf.
	in order to print it '%%' is needed.

	if the format specifier is not recognised *i is decremented, this is because
	the format specifier would not normally be printed in ft_printf and *i is
	incremented to acheive this. so in order to print the character after '%'
	*i needs to be decremented.

	Inputs
	fs = a character representing the format specifier.
	args = a va_list pointer containing the list of arguments.
	length = a pointer to the length counter.
	i = a pointer to the index counter.

	Outputs
	none.
 */
static	void	ft_format_specifier(char fs, va_list *args, int *length, int *i)
{
	if (fs == 'c')
		ft_character(va_arg(*args, int), length);
	else if (fs == 's')
		ft_string(va_arg(*args, char *), length);
	else if (fs == 'p')
		ft_pointer(va_arg(*args, size_t), length, 1);
	else if (fs == 'd' || fs == 'i')
		ft_decimal_integer(va_arg(*args, int), length);
	else if (fs == 'u')
		ft_unsigned_integer(va_arg(*args, unsigned int), length);
	else if (fs == 'x')
		ft_hexidecimal(va_arg(*args, unsigned int), length, 'x', 1);
	else if (fs == 'X')
		ft_hexidecimal(va_arg(*args, unsigned int), length, 'X', 1);
	else if (fs == '%')
		ft_character('%', length);
	else
		(*i)--;
}

/*
	Summary
	ft_printf
	prints a variable number and type of arguments (...) to the standard output

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
	string = the format string that specifies the desired output format.
	... = variable number of arguments that correspond to the format specifiers
	in the format string.

	Outputs
	length = the total number of characters printed to the standard output.
*/
int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_format_specifier(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_character(string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
