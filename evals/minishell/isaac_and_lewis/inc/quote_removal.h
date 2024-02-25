/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:18:06 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 10:44:49 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_REMOVAL_H
# define QUOTE_REMOVAL_H

# include "libft.h"
# include "lexer.h"

void	remove_empty_words(t_deque *tokens);
void	remove_quotes_tokens(t_deque *tokens);
void	remove_quotes_string(char *str);

int		node_is_empty(t_dlist *node);
void	remove_empty_words(t_deque *tokens);

#endif
