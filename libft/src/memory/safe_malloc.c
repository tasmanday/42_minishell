/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:44:03 by tday              #+#    #+#             */
/*   Updated: 2024/03/01 13:58:44 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	**** ALLOCATES MEMORY ****

	Summary
	a wrapper around the malloc function. allocates memory and returns a
	pointer to the allocated memory. If the malloc function fails, the
	safe_malloc function calls the error_exit function to handle the error.

	Inputs
	bytes: The number of bytes to allocate.

	Outputs
	result: a pointer to the allocated memory.
*/
void	*safe_malloc(size_t bytes, char *error_message)
{
	void	*result;

	result = malloc(bytes);
	if (!result)
		error_exit(error_message);
	return (result);
}
