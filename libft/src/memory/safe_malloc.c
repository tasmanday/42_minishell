/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:44:03 by tday              #+#    #+#             */
/*   Updated: 2024/01/27 17:47:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	a wrapper around the malloc function. allocates memory and returns a
	pointer to the allocated memory. If the malloc function fails, the
	safe_malloc function calls the error_exit function to handle the error.

	Inputs
	bytes: The number of bytes to allocate.

	Outputs
	result: a pointer to the allocated memory.
*/
void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (result == NULL)
		error_exit("error with malloc");
	return (result);
}
