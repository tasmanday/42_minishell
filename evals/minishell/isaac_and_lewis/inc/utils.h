/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:35:31 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:40:45 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "builtins.h"

char	**msh_clone_envv(char **envv);
void	ft_dlist_append_end(t_dlist **head, t_dlist *new_node);
void	ft_deque_append_deque(t_deque *d1, t_deque d2);
void	list_bubble_sort(t_list *head, int (*cmp)(void *, void *));
void	deque_bubble_sort(t_deque d, int (*cmp)(void *, void *));
void	free_char_array(char **arr);
void	print_err(char *fmt, ...);
int		get_deque_size(t_deque *tokens);
char	**linked_list_to_char_array(t_list *head);
t_list	*char_array_to_linked_list(char **arr);
int		str_has_quote_char(const char *str);
void	free_array_til(char **arr, int n);

#endif
