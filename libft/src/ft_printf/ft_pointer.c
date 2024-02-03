/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:06:28 by tday              #+#    #+#             */
/*   Updated: 2024/01/15 00:06:28 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	prints the memory address of a pointer to the standard output as a
	hexadecimal character and increases the value at &length by using
	ft_character

	if (first)
	checks if this is the first instance of this function and if so prints the 
	prefix "0x" as memory addresses start with that

	if (p == 0)
	checks if this is the first time the function has been called and if so
	prints '0' meaning the address would be "0x0" or NULL
	it needs to be able to print '0' in the first instance if p is 0 but 
	without the first check, it would print '0' before the hex number because
	the final p / 16 = 0

	else if (p > 0)
	sets first to '0' (false) and recursively calls the function with (p / 16) 
	until p = 0
	this essentially removes the rightmost digit from the hexadecimal number 
	each time, the same as d / 10 for a decimal number
	once p = 0 it prints the leftmost digit in hexadecimal notation by getting
	the modulus 16 of the most recently called number and then printing that
	digit from the hexadecimal base
	it then does the same with each digit of the number until all digits are 
	printed.
	eg. p = 77
	77 / 16 = 4
			4 / 16 = 0
					0 !> 0 so recursion finishes, '0' is not printed because
							first is now '0' (false)
			4 % 16 = 4 so '4' is printed
	77 % 16 = 13 so 'd' is printed as that is the 13th digit in the base
	output is "0x4d"

	Inputs
	p = the memory address of the pointer
	length = pointer to an integer that maintains the count of how many
	characters have been printed.
	first = a flag to indicate the first time the function has been called
	this handles the edge case when p = 0.

	Outputs
	none.
 */
void	ft_pointer(size_t p, int *length, int first)
{
	char	*hexidecimal_base;

	hexidecimal_base = "0123456789abcdef";
	if (first)
	{
		write(1, "0x", 2);
		(*length) += 2;
	}
	if (p == 0)
	{
		if (first)
			ft_character('0', length);
		return ;
	}
	else if (p > 0)
	{
		ft_pointer((p / 16), length, 0);
		ft_character(hexidecimal_base[p % 16], length);
	}
}
