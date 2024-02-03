/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_even.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:25:00 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 20:29:57 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if a given integer is even.

	Inputs
	n = given integer.

	Outputs
	1 if the given integer is even, 0 if it's odd.
*/
int	ft_is_even(long long n)
{
	return (n % 2 == 0);
}
