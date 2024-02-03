/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:58:15 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 23:58:15 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	prints an unsigned int to the standard output as a hexadecimal character
	and increases the value at &length by using ft_character.

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
	x = a hexadecimal integer.
	length = pointer to an integer that maintains the count of how many
	characters have been printed.
	char_case = a flag for detemining between uppercase and lowercase
	hexadecimal digits.
	first = a flag to indicate the first time the function has been called
	this handles the edge case when x = 0.

	Outputs
	none.
 */
void	ft_hexidecimal(unsigned int x, int *length, char char_case, int first)
{
	char	*hexidecimal_base;

	if (char_case == 'X')
		hexidecimal_base = "0123456789ABCDEF";
	else
		hexidecimal_base = "0123456789abcdef";
	if (x == 0)
	{
		if (first)
			ft_character('0', length);
		return ;
	}
	else if (x > 0)
	{
		ft_hexidecimal((x / 16), length, char_case, 0);
		ft_character(hexidecimal_base[x % 16], length);
	}
}
