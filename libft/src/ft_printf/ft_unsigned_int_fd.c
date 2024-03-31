/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:15:44 by tday              #+#    #+#             */
/*   Updated: 2024/03/31 20:15:44 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if u is a single digit number and if not uses recursion to print
	it one digit at a time from left to right.
	it does this by removing the rightmost digit with u / 10 and then calling
	the ft_u_i function again with that number.
	that continues until u is a single digit (leftmost) at which point it
	prints u % 10 (rightmost digit of the current number) using ft_character.
	it then does the same with each itteration of the number until all digits
	are printed.
	eg. u = 123
	123 / 10 = 12
			12 / 10 = 1
					1 < 10 so recursion finishes and '1' is printed
			12 % 10 = 2 so '2' is printed
	123 % 10 = 3 so '3' is printed
	since u is an unsigned int it doesn't need to handle negative numbers

	Inputs
	[int] fd: file desciptor to output to.
	[unsigned int] u: an unsigned integer.
	[int *] length: pointer to an integer that keeps count of how many
		characters have been printed.

	Outputs
	none.
 */
void	ft_unsigned_integer_fd(int fd, unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_integer_fd(fd, (u / 10), length);
	ft_character_fd(fd, ((u % 10) + '0'), length);
}
