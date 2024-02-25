/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:22:25 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:34:03 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include "libft.h"
# include "source.h"

enum e_token_node_type {
	NONE_TYPE,
	OPERATOR,
	WORD,
	REDIRECTION_WORD,
	REDIRECTION_DELIMITER,
	REDIRECTION_HEREDOC,
};

union u_content {
	enum e_operator	op;
	char			*str;
	int				fd;
};

typedef struct s_token_node {
	enum e_token_node_type	type;
	union u_content			content;
}	t_token_node;

t_token_node	*clone_token_node(t_token_node *t);
t_deque			source_to_tokens(t_source *src);

/*				lexer1.c*/
void			delete_token_node_void(void *ptr);
void			delete_token_node(t_token_node *token);
t_token_node	*new_token_node(void);
t_token_node	*new_str_t_n(enum e_token_node_type type, char *str);
t_token_node	*new_operator_token_node(enum e_operator op);

#endif
