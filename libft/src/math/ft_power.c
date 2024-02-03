/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:32:17 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 20:35:07 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	calculates the power of a given integer.

	Inputs
	n = base number.
	power = exponent.

	Outputs
	result of raising n tp the power of power.
*/
long long	ft_power(long long n, long long power)
{
	long long	result;

	if (power == 0)
		return (1);
	else if (power <= 0)
		return (0);
	result = 1;
	while (power--)
		result *= n;
	return (result);
}
