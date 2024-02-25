/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:14:38 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:31:33 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "lexer.h"
# include "libft.h"
# include "redirection.h"
# include "tilde_expansion.h"
# include "utils.h"

typedef struct s_command {
	t_list	*args;
	t_list	*redirections;
	int		fd_in;
	int		fd_out;
}	t_command;

/*			command.c*/
t_command	*new_command(void);
void		delete_command(t_command *cmd);
int			new_cmd_from_tokens_do_3(t_command *cmd, t_token_node *token);
int			new_cmd_from_tokens_do_4(t_command *cmd, t_deque *tokens);
t_command	*new_cmd_from_tokens(t_deque *tokens, char **envv, int last_exit);

/*			command1.c*/
int			check_one(t_token_node *token);
int			check_two(t_token_node *token);
int			check_three(t_token_node *token, t_redirection *redirection);
void		new_cmd_from_tokens_do_1(t_token_node *token,
				t_redirection *redirection);
int			new_cmd_from_tokens_do_2(t_command *cmd, t_token_node *token,
				t_deque *tokens);

#endif
