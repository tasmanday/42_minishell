/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:17:27 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 20:20:24 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	returns the absolute (positive) value of an integer.

	Inputs
	n = given integer.

	Outputs
	the absolute value of the given integer.
*/
long long	ft_abs(long long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
