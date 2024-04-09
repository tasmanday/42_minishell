/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:48:39 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 21:37:40 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	**** ALLOCATES MEMORY ****

	Summary
	reallocates memory for a given pointer.

	Inputs
	pointer = a pointer to the memory block to be reallocated.
	orig_size = the original size of the memory block in bytes.
	new_size = the new size of the memory block in bytes.

	Outputs
	if new_size is 0, it frees the memory.
	if the pointer is NULL, it allocates a new block of memory of size
	new_size using malloc.
	if new_size is less than or equal to orig_size, it returns the original
	pointer without making any changes.
	if the pointer is not NULL and new_size is greater than orig_size, it
	allocates a new block of memory of size new_size, copies the contents of
	the original memory block to the new block using ft_memcpy, frees the
	original memory block, and returns the new pointer.
*/
void	*ft_realloc(void *pointer, size_t orig_size, size_t new_size)
{
	void	*new_pointer;

	new_pointer = 0;
	if (new_size == 0)
		free(pointer);
	else if (!pointer)
	{
		new_pointer = ft_calloc(1, new_size);
		if (!new_pointer)
			return (error("ft_realloc malloc error"), NULL);
	}
	else if (new_size <= orig_size)
		return (pointer);
	else if (pointer && new_size > orig_size)
	{
		new_pointer = ft_calloc(1, new_size);
		if (!new_pointer)
			return (error("ft_realloc malloc error"), NULL);
		ft_memcpy(new_pointer, pointer, orig_size);
		free(pointer);
	}
	return (new_pointer);
}
