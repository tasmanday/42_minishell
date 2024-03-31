/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_integer_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:19:23 by tday              #+#    #+#             */
/*   Updated: 2024/03/31 19:19:23 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* 
	Summary
	prints a decimal integer to the given file descriptor and increases the
	value at &length by using ft_character_fd.

	if (d == -2147483648)
	handles MININT as it cannot be made positive.

	if (d < 0)
	prints '-', then converts the integer to a positive value and recersively
	calls the function.

	else
	checks if d is a single digit number and if not uses recursion to print
	it one digit at a time from left to right.
	it does this by removing the rightmost digit with d / 10 and then calling
	the ft_d_i function again with that number.
	that continues until d is a single digit (leftmost) at which point it
	prints d % 10 (rightmost digit of the current number) using ft_character.
	it then does the same with each itteration of the number until all digits
	are printed.
	eg. d = 123
	123 / 10 = 12
			12 / 10 = 1
					1 < 10 so recursion finishes and '1' is printed
			12 % 10 = 2 so '2' is printed
	123 % 10 = 3 so '3' is printed

	Inputs
	[int] fd: file desciptor to output to.
	[int] d: a decimal integer.
	[int *] length: pointer to an integer that keeps count of how many
	characters have been printed.

	Outputs
	none.
 */
void	ft_decimal_integer_fd(int fd, int d, int *length)
{
	if (d == -2147483648)
	{
		write(fd, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (d < 0)
	{
		ft_character_fd(fd, '-', length);
		ft_decimal_integer_fd(fd, (d * -1), length);
	}
	else
	{
		if (d >= 10)
			ft_decimal_integer_fd(fd, (d / 10), length);
		ft_character_fd(fd, ((d % 10) + '0'), length);
	}
}
