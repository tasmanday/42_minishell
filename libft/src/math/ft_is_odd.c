/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_odd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:28:07 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 20:28:49 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	checks if a given integer is odd.

	Inputs
	n = given integer.

	Outputs
	true if the given integer is odd, false if it's even.
*/
bool	ft_is_odd(long long n)
{
	return (n % 2 == 1);
}
