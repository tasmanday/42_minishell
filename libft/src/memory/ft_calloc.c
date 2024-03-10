/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:19:27 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 21:37:04 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	**** ALLOCATES MEMORY ****

	Summary
	ft_calloc allocates memory and initialises each byte of that memory to 0
	('\0').

	Inputs
	number = number of elements to allocate.
	size = size of each element.
	pointer = pointer to start of allocated memory.

	Outputs
	none.
*/
void	*ft_calloc(size_t number, size_t size)
{
	void	*pointer;

	pointer = malloc(number * size);
	if (!pointer)
	{
		error("ft_calloc error");
		return (NULL);
	}
	ft_bzero(pointer, number * size);
	return (pointer);
}
