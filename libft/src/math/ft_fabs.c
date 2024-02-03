/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:21:37 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 20:23:04 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	returns the absolute (positive) value of a float.

	Inputs
	n = given float.

	Outputs
	the absolute value of the given float.
*/
long double	ft_fabs(long double n)
{
	if (n < 0)
		n *= -1.0;
	return (n);
}
