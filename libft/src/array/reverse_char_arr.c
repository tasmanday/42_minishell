/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_char_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:23:25 by tday              #+#    #+#             */
/*   Updated: 2024/01/26 11:28:28 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	reverses the order of the character elements in the array.
	*** if trying to reverse a string size should be (strlen(arr) - 1) ***

	Inputs
	arr = an array of characters.
	size = the size of the array.

	Outputs
	none.
*/
void	reverse_char_arr(char *arr, int size)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
		i++;
	}
}
