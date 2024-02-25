/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:57:47 by lxu               #+#    #+#             */
/*   Updated: 2023/09/21 16:33:05 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "lexer.h"
# include "libft.h"
# include "redirection.h"
# include "utils.h"

// typedef	struct s_command {
// 	char	*cmd;
// 	t_list	*args;
// 	int		in;
// 	int		out;
// 	t_list	*redirections_in;
// 	t_list	*redirections_out;
// 	pid_t	pid;
// }	t_command;

enum e_ast_type {
	AST_NONE,
	AST_PIPE,
	AST_AND,
	AST_OR,
	AST_CMD,
	AST_BRACKETS,
};

typedef struct s_ast_node	t_ast_node;

typedef struct s_ast_node {
	enum e_ast_type	type;
	int				fd_in;
	int				fd_out;
	t_deque			tokens;
	t_ast_node		*left;
	t_ast_node		*right;
}	t_ast_node;

/*		parse.c*/
t_ast_node		*create_command_ast_node(t_deque d);
t_ast_node		*create_bracket_ast_node(t_deque *left, t_deque *right);
t_ast_node		*create_pipe_and_or_ast_node(enum e_operator op, t_deque left, \
	t_deque right);
t_ast_node		*parse_tokens_recursive(t_deque d);
t_ast_node		*parse_tokens_from_deque(t_deque *d);

/*		parse1.c*/
t_ast_node		*new_ast_node(void);
void			delete_ast_node(t_ast_node *node);
void			ast_node_preorder_apply(t_ast_node *node, \
	void (*f)(t_ast_node *));
void			ast_node_postorder_apply(t_ast_node *node, \
	void (*f)(t_ast_node *));
void			delete_ast_tree(t_ast_node *head);

/*		parse2.c*/
t_dlist			*tokens_next_split_location(t_deque tokens);

/*		parse3.c*/
enum e_operator	split_tokens_with_cleanup(t_deque *source, t_deque *left, \
	t_deque *right, t_dlist *split_loc);

#endif
