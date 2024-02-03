/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:16:11 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 14:28:52 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	counts the number of characters in a string (stops counting at null
	terminator '\0').

	Inputs
	string = a pointer to the null-terminated string to be counted.

	Outputs
	count = the count of the number of characters in the string excluding the
	null-terminator.
*/
size_t	ft_strlen(const char *string)
{
	size_t	count;

	count = 0;
	if (!string)
		return (0);
	while (string[count] != '\0')
		count++;
	return (count);
}
