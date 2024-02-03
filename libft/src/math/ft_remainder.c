/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remainder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:10:36 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 21:25:45 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	calculates the remainder of dividing the numerator by the denominator.

	Inputs
	numerator = the number to be divided.
	denominator = the number to divide by.

	Outputs
	the remainder of dividing the numerator by the denominator.
*/
long double	ft_remainder(long double numerator, long double denominator)
{
	if (numerator < 0)
		numerator *= -1;
	return (numerator - (denominator * (long long)(numerator / denominator)));
}
