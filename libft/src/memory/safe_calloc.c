/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:18:44 by tday              #+#    #+#             */
/*   Updated: 2024/03/10 21:18:44 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	**** ALLOCATES MEMORY ****

	Summary
	a wrapper around the ft_calloc function. allocates memory and returns a
	pointer to the allocated memory. If the ft_calloc function fails, the
	safe_calloc function calls the error_exit function to handle the error.

	Inputs
	[size_t] number: The number of elements to allocate.
	[size_t] size: The size of each element in bytes.
	[char *] error_message: The error message to be passed to error_exit
		function in case of memory allocation failure.

	Outputs
	result: a pointer to the allocated memory.
*/
void	*safe_calloc(size_t number, size_t size, char *error_message)
{
	void	*result;

	result = ft_calloc(number, size);
	if (!result)
		error_exit(error_message);
	return (result);
}
