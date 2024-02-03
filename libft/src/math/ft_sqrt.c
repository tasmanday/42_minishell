/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:36:33 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 20:46:14 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	calculates the square root of a given number using a binary search
	algorithm, as long as it is a perfect square.

	Inputs
	n = given number

	Outputs
	the square root of 'n' if 'n' is a perfect square.
	otherwise 0 if it is not.
*/
long long	ft_sqrt(long long n)
{
	long long	temp;
	long long	i;

	temp = n;
	i = 1;
	while (temp - i > 0)
	{
		temp = (temp + i) / 2;
		i = n / temp;
	}
	if (temp * temp == n)
		return (temp);
	else
		return (0);
}
