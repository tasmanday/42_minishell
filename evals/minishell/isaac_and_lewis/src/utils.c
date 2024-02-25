/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:39:49 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:39:06 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief clone envv from main's parameters into our own malloced copy for
 * further manipulation.
 *
 * @param envv A copy of our valid environmental variable array.
 */
char	**msh_clone_envv(char **envv)
{
	char	**new_envv;
	int		envv_len;
	int		i;

	envv_len = get_array_height(envv);
	new_envv = malloc(sizeof(char *) * (envv_len + 1));
	if (!new_envv)
	{
		return (NULL);
	}
	i = 0;
	while (envv[i])
	{
		new_envv[i] = ft_strdup(envv[i]);
		if (!new_envv[i])
		{
			return (NULL);
		}
		i++;
	}
	new_envv[i] = NULL;
	return (new_envv);
}

/**
 * @brief Append a dlist onto the end of another dlist.
 *
 * Updates pointers to append a dlist onto the tail of another dlist. If the
 * original dlist is empty then updates all the pointers to make it point to the
 * dlist being appended.
 * 
 * Nb. Difference between ft_dlist_append_end and ft_dlist_insert_end is that
 * insert end is to append a single node and as a precaution sets the next
 * pointer to null. This by comparison allows the appended list to continue.
 *
 * @param head A pointer to the head of dlist to be appended onto.
 * @param new_node The head of the new dlist to be appended.
 */
void	ft_dlist_append_end(t_dlist **head, t_dlist *new_node)
{
	t_dlist	*last;

	if (!head | !new_node)
	{
		return ;
	}
	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	last = ft_dlist_get_last(*head);
	last->next = new_node;
	new_node->prev = last;
	return ;
}

/**
 * @brief Append a deque onto the end of another deque
 *
 * Efficiently appends a deque onto the end of another deque. Assumes that both
 * deques are properly formed.
 *
 * @param t_deque *deque1 The parent deque to be appended onto. Passed as
 *     pointer so that the head and tail values can be adjusted after append.
 * @param t_deque deque2 The deque to be attached onto the end of deque1.
 */
void	ft_deque_append_deque(t_deque *d1, t_deque d2)
{
	if (!d1)
	{
		return ;
	}
	if (d2.head == NULL)
	{
		return ;
	}
	if (d1->head == NULL)
	{
		d1->head = d2.head;
		d1->tail = d2.tail;
		return ;
	}
	d1->tail->next = d2.head;
	d2.head->prev = d1->tail;
	d1->tail = d2.tail;
}

void	free_char_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
 * @brief  	frees whatever we have already malloced in our new env array
 * 			used in the case of failure to ft_strdup/malloc new memory.
 *
 * @param 	char **arr our array that requires freeing til n.
 * @param 	int	n the number of elements we need to free in our array
*/
void	free_array_til(char **arr, int n)
{
	int	i;

	i = 0;
	while (arr[i] && i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
