/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:25:25 by tday              #+#    #+#             */
/*   Updated: 2024/03/31 19:25:25 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	wrapper function handles the edge case when x = 0. otherwise calls the 
	recursive function ft_hex_fd_recursive.

	Inputs
	[int] fd: file desciptor to output to.
	[unsigned int] x: a hexadecimal integer.
	[int *] length: pointer to an integer that keeps count of how many
		characters have been printed.
	[char] char_case = a flag for detemining between uppercase and lowercase
		hexadecimal digits.

	Outputs
	none.
*/
void	ft_hexadecimal_fd(int fd, unsigned int x, int *length, char char_case)
{
	if (x == 0)
		ft_character_fd(fd, '0', length);
	else
		ft_hex_fd_recursive(fd, x, length, char_case);
}

/*
	Summary
	prints an unsigned int to the givrn file descriptor as a hexadecimal
	character and increases the value at &length by using ft_character.

	if (char_case == 'X')
	sets the case of the hex characters, 'x' = lower, 'X' = upper.

	if (x == 0)
	checks if this is the first time the function has been called and if so
	prints '0'.
	it needs to be able to print '0' if x is 0 but without the first check,
	it would print '0' before the hex number because the final x / 16 = 0.

	else if (x > 0)
	sets first to '0' (false) and recursively calls the function with (x / 16) 
	until x = 0.
	this essentially removes the rightmost digit from the hexadecimal number 
	each time, the same as d / 10 for a decimal number.
	once x = 0 it prints the leftmost digit in hexadecimal notation by getting
	the modulus 16 of the most recently called number and then printing that
	digit from the hexadecimal base, it then does the same with each digit of
	the number until all digits are printed.
	eg. x = 77
	77 / 16 = 4
			4 / 16 = 0
					0 !> 0 so recursion finishes, '0' is not printed because
							first is now '0' (false)
			4 % 16 = 4 so '4' is printed
	77 % 16 = 13 so 'd' is printed as that is the 13th digit in the base
	output is "4d" if charcase == 'x' or "4D" if it is 'X'

	Inputs
	[int] fd: file desciptor to output to.
	[unsigned int] x: a hexadecimal integer.
	[int *] length: pointer to an integer that keeps count of how many
		characters have been printed.
	[char] char_case = a flag for detemining between uppercase and lowercase
		hexadecimal digits.

	Outputs
	none.
 */
void	ft_hex_fd_recursive(int fd, unsigned int x, int *length, char char_case)
{
	char	*hexidecimal_base;

	if (char_case == 'X')
		hexidecimal_base = "0123456789ABCDEF";
	else
		hexidecimal_base = "0123456789abcdef";
	if (x == 0)
		return ;
	else if (x > 0)
	{
		ft_hex_fd_recursive(fd, (x / 16), length, char_case);
		ft_character_fd(fd, hexidecimal_base[x % 16], length);
	}
}
