/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:25:37 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:27:39 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

/**
 * @brief Create source object from heap string.
 *
 * A source object contains a heap string that can be navigated around.
 * Functions are provided that operate on the source object to "take" characters
 * off the end of the source while keeping track of the "current position"
 * within the string.
 *
 * @param buff The source string to be copied in.
 * @return A heap allocated source object.
*/
t_source	*new_source(char *buff)
{
	t_source	*src;

	src = malloc(sizeof(t_source) * 1);
	if (src == NULL)
	{
		return (src);
	}
	src->buff = ft_strdup(buff);
	src->buff_size = ft_strlen(src->buff);
	src->pos = 0;
	return (src);
}

/**
 * @brief Deletes a heap allocated source object.
 *
 * Deletes a heap allocated source object including the heap buff string.
*/
void	delete_source(t_source *src)
{
	free(src->buff);
	free(src);
}

/**
 * @brief Takes and returns the next char in the source object.
 *
 * "Takes" the next char in the source object by incrementing the current
 * position within the object.
 *
 * @param src The source object to operate on.
 * @return The char found at that position. 
 * @return NULL char if past the end of the string.
 */
char	take_char(t_source *src)
{
	char	c;

	c = (src->buff)[src->pos];
	if (src->pos < src->buff_size)
	{
		src->pos += 1;
	}
	return (c);
}

/**
 * @brief Peeks at the next char in the source object.
 *
 * "Peeks" at the next char in the source object. Returns the char at the next
 * index but does not modify the current position.
 * @param src The source object to operate on.
 * @return The char found at that position.
 * @return NULL char if at the end of the string.
 */
char	peek_char(t_source *src)
{
	return ((src->buff)[src->pos]);
}

/**
 * @brief Peeks at the char following the next char.
 *
 * Peeks at the next, next char.
 *
 * @param src The source object to operate on.
 * @return The char found at that position.
 * @return NULL char if you have fallen off the end.
 */
char	peek_peek_char(t_source *src)
{
	if (src->pos + 1 >= src->buff_size)
	{
		return ('\0');
	}
	return ((src->buff)[src->pos + 1]);
}
