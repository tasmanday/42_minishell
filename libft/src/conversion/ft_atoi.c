/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:42:52 by tday              #+#    #+#             */
/*   Updated: 2024/01/16 22:42:52 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if adding the next digit to the given number will cause an overflow,
	based on the maximum value of a long long integer.

	Inputs
	nb = the current number.
	next_digit = the next digit to be added to the number.
	sign = the sign of the number (1 = pos, -1 = neg).

	Outputs
	0 if adding the next digit will not cause an overflow, 1 if it will.
*/
static int	exceeds_llong_max(long long nb, char next_digit, int sign)
{
	int	exceeds_limit;

	exceeds_limit = 0;
	if (nb == LLONG_MAX / 10 && next_digit <= '7' && sign == 1)
		exceeds_limit = 0;
	else if (nb == LLONG_MAX / 10 && next_digit <= '8' && sign == -1)
		exceeds_limit = 0;
	else if (nb >= LLONG_MAX / 10)
	{
		error("ft_atoi error: string exceeds long long max");
		exceeds_limit = 1;
	}
	return (exceeds_limit);
}

/*
	Summary
	converts a string repressentation of an integer to a 'long long' integer.

	Inputs
	str = a pointer to a string representing an integer.

	Outputs
	the converted 'long long' integer value of the input string, or '0' if it
	causes an overflow.
*/
long long	ft_atoi(const char *str)
{
	long long	result;
	int			i;
	int			sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (exceeds_llong_max(result, *str, sign))
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
