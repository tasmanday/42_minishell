/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:07:32 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 12:29:11 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

/**
 * @brief Create and return a new empty redirection heap struct
 *
 * Allocates a redirection struct on the heap. Sets it's values to "null" values
 * and returns a pointer to it.
 *
 * @return A new heap redirection object.
 */
t_redirection	*new_redirection(void)
{
	t_redirection	*r;

	r = malloc(sizeof(t_redirection) * 1);
	if (!r)
	{
		return (NULL);
	}
	r->type = REDIRECTION_NONE;
	r->file_name = NULL;
	r->old_fd = -1;
	r->new_fd = -1;
	return (r);
}

/**
 * @brief Delete a redirection object
 *
 * Deletes a redirection struct that was allocated on the heap. Frees the values
 * held inside and closes any open file descriptors before freeing the
 * redirection object itself.
 *
 * @param r The redirection object to be deleted.
 */
int	delete_redirection(t_redirection *r)
{
	if (!r)
	{
		return (1);
	}
	if (r->file_name)
	{
		free(r->file_name);
	}
	if (r->new_fd >= 0)
	{
		close(r->new_fd);
	}
	free(r);
	return (1);
}

/**
 * @brief Void helper for delete redirection
 *
 * Void pointer wrapper to allow use in functions expecting a void(*f)(void *)
 * function signature.
 *
 * @param void_ptr Void pointer to a redirection object.
 */
void	delete_redirection_void(void *void_ptr)
{
	t_redirection	*r;

	r = (t_redirection *)void_ptr;
	delete_redirection(r);
}

/**
 * @brief Redirection object constructor with passed in operator
 *
 * Takes a passed in operator and creates a new redirection object with the type
 * set appropriately depending on the operator symbol passed in.
 *
 * @param op The operator symbol to set the redirection type.
 * @return A new redirection object with the type set appropriately.
 */
t_redirection	*new_redirection_with_type_from_op(enum e_operator op)
{
	t_redirection	*r;

	r = new_redirection();
	if (!r)
		return (NULL);
	if (op == LESS_THAN)
		r->type = REDIRECTION_IN;
	else if (op == DOUBLE_LESS_THAN)
		r->type = REDIRECTION_IN_HEREDOC;
	else if (op == GREATER_THAN)
		r->type = REDIRECTION_OUT;
	else if (op == DOUBLE_GREATER_THAN)
		r->type = REDIRECTION_OUT_APPEND;
	else
	{
		print_err("msh_internal: new_redirection_with_type_from_op\n");
		return (NULL);
	}
	return (r);
}

/**
 * @brief Print error message for open errors.
 * 
 * @param file_name The string file name that was being opened.
 */
void	print_open_error(char *file_name)
{
	print_err("msh: %s: ", file_name);
	perror("");
}
