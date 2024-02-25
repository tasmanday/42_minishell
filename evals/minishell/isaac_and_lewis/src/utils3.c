/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:39:49 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:37:41 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Take a linked list of strings and return it as a char array.
 *
 * Linked list content is assumed to be char strings.
 * Char strings in the array are duplicated from the linked list rather than
 * just duplicating the pointers.
 *
 * @param head The head node of the linked list.
 * @return A null terminated pointer array pointing to heap char strings.
 */
char	**linked_list_to_char_array(t_list *head)
{
	char	**arr;
	size_t	i;
	t_list	*node;

	arr = malloc((sizeof(char *)) * (ft_lstsize(head) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	node = head;
	while (node)
	{
		arr[i] = ft_strdup(node->content);
		if (!arr[i])
		{
			free_array_til(arr, i);
			return (NULL);
		}
		i++;
		node = node->next;
	}
	arr[i] = NULL;
	return (arr);
}

/**
 * @brief Take a char array and return a linked list of char strings.
 *
 * Takes a null terminated array of pointers to char strings. Creates and
 * returns a linked list with content being these heap strings. Clones the
 * strings into new heap memory.
 *
 * @param arr Pointer to the first element of the pointer array.
 * @return A null terminated pointer list pointing to heap char strings.
 */
t_list	*char_array_to_linked_list(char **arr)
{
	t_list	*head;
	t_list	*node;
	size_t	i;
	char	*str;

	head = NULL;
	i = 0;
	while (arr[i])
	{
		str = ft_strdup(arr[i]);
		if (!str)
		{
			return (head);
		}
		node = ft_lstnew(str);
		if (!node)
		{
			free(str);
			return (head);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

/**
 * @brief Determine if a given string contains the " or ' character.
 *
 * @param str: the comparison string.
 * @return 1 boolean True if string has quote char.
 *         0 boolean False if string does not have quote char.
 */
int	str_has_quote_char(const char *str)
{
	size_t	i;

	if (!str)
	{
		return (0);
	}
	i = 0;
	while (str[i])
	{
		if (ft_isinstr(str[i], "\'\""))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
