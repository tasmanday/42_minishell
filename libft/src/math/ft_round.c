/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:07:53 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 22:10:10 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	rounds a floating point number to the nearest integer.

	Inputs
	n = given floating point number

	Outputs
	the given floating point number rounded to the nearest integer.
*/
long long	ft_round(long double n)
{
	long long	result;

	if (n >= 0)
		result = (long long)(n + 0.5);
	else
		result = (long long)(n - 0.5);
	return (result);
}
