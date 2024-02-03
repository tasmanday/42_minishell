/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:11:48 by tday              #+#    #+#             */
/*   Updated: 2024/01/17 22:12:48 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	calculates the length of an integer by recursively dividing it by 10 until
	it becomes < 10.

	Inputs
	n = the integer for wich the length needs to be calculated.

	Outputs
	the length of the integer.
*/
size_t	ft_get_len_int(long long n)
{
	if (0 <= n && n < 10)
		return (1);
	else if (-10 < n && n < 0)
		return (2);
	return (1 + ft_get_len_int(n / 10));
}
