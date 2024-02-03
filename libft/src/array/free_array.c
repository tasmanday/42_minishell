/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:51:01 by tday              #+#    #+#             */
/*   Updated: 2024/01/26 11:01:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	frees the memory allocated for each element in the array pointed to by
	arr_ptr using the free_null function, and then frees the memory allocated
	for the array itself using the free function.

	Inputs
	arr_ptr = a double pointer to an array of pointers (double pointer is
	required to modify the array pointer).

	Outputs
	none.
*/
void	free_array(void **arr_ptr)
{
	int	i;

	if (!arr_ptr)
		return ;
	i = 0;
	while (arr_ptr[i])
		free_null(&arr_ptr[i++]);
	free(arr_ptr);
}
