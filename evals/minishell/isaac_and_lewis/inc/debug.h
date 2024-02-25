/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:56:48 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:32:04 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "libft.h"
# include "lexer.h"
# include <stdio.h>
# include "parse.h"
# include "bool.h"
# include "command.h"

void	debug_print_tokens(t_deque tokens);
void	debug_print_token_node(t_token_node *token_node);
void	debug_print_ast_tree(t_ast_node *node, char **envv);
void	debug_print_command_oneline(t_ast_node *node, char **envv);
void	debug_pretty_print_ast_tree(t_ast_node *node, char **envv);

#endif
