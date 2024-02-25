/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:03:02 by lxu               #+#    #+#             */
/*   Updated: 2023/08/02 21:22:36 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <stdlib.h>

/**
 * @struct t_dlist
 * A double ended list.
 *
 * A double ended list. A list with pointers to both the next and the previous
 * nodes. Therefore, the list can be traversed (and edited) from either end.
 * These are nodes of a dlist, when strung together forms the completed dlist.
 * The functions typically expect to be passed the head node of a dlist.
 *
 * @var t_dlist::content
 *     Void pointer to the content included in this node
 * @var t_dlist::next
 *     Pointer to the next s_dlist node. NULL if there is no next node (ie if
 *     the node is the last node).
 * @var t_dlist::prev
 *     Pointer to the previous s_dlist node. NULL if no previous node (ie if
 *     the node is the head node).
 */
typedef struct s_dlist {
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

t_dlist	*ft_dlist_new_node(void *content);
void	ft_dlist_destroy_node(t_dlist *node, void (*del)(void *));
void	ft_dlist_destroy_list(t_dlist *head, void (*del)(void *));
t_dlist	*ft_dlist_get_last(t_dlist *head);
void	ft_dlist_remove_first(t_dlist **head, void (*del)(void *));
void	ft_dlist_remove_last(t_dlist **head, void (*del)(void *));
void	ft_dlist_insert_start(t_dlist **head, t_dlist *new_node);
void	ft_dlist_insert_end(t_dlist **head, t_dlist *new_node);
t_dlist	*ft_dlist_pop_first(t_dlist **head);
t_dlist	*ft_dlist_pop_last(t_dlist **head);
t_dlist	*ft_dlist_pop_at_pointer(t_dlist **head, t_dlist *node);
size_t	ft_dlist_length(t_dlist *head);

#endif