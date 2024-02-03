/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:35:35 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 22:06:34 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	rounds a given number to a specified number of decimal places.

	Inputs
	n = given floating point number.
	decimal_places = number of decimal places desired.

	Outputs
	the given floating point number rounded to the specified number of decimal
	places.
*/
long double	ft_roundf(long double n, int decimal_places)
{
	double		power;
	long double	result;

	if (decimal_places <= 0)
		return (0);
	power = ft_power(10, decimal_places);
	n *= power;
	if (n >= 0)
		result = (long long)(n + 0.5) / power;
	else
		result = (long long)(n - 0.5) / power;
	return (result);
}

/* int	main(void)
{
	long double	result;

	result = ft_roundf(42.123456789, 3);
	printf("result: %.9Lf\n", result);
	return (0);
} */
