/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:17:24 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 13:04:35 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repl.h"

/**
 * @brief One pass of the REPL loop
 * 
 * Runs one loop of the REPL. Updates the last exit value if appropriate.
 * 
 * If has error during one cycle, cleans up and returns allowing for main REPL
 * to start over.
 * 
 * @param msh_envp The pointer to the shared environment.
 * @param last_exit_ptr The pointer to the last exit value.
 */

void	repl_once_do(int *last_exit_ptr, t_deque *d, int exit_set)
{
	*last_exit_ptr = exit_set;
	ft_deque_destroy_list(d, delete_token_node_void);
}

void	repl_once(char ***msh_envp, int *last_exit_ptr)
{
	char		*line;
	t_source	*s;
	t_deque		d;
	t_ast_node	*a;
	int			ret;

	setup_term();
	sig_initialiser_during_read();
	line = msh_readline(PS1, *msh_envp, last_exit_ptr);
	reset_term();
	if (quotes_valid(line) == 0)
		return (free(line));
	s = new_source(line);
	free(line);
	d = source_to_tokens(s);
	delete_source(s);
	if (syntax_is_valid(d) == 0)
		return (repl_once_do(last_exit_ptr, &d, 2));
	sig_initialiser_during_heredoc();
	ret = enter_heredocs(d, *msh_envp, *last_exit_ptr);
	if (ret)
		return (repl_once_do(last_exit_ptr, &d, ret));
	a = parse_tokens_from_deque(&d);
	sig_initialiser_during_execute();
	*last_exit_ptr = do_ast_node(a, msh_envp, *last_exit_ptr);
}

/**
 * @brief The primary REPL loop.
 * 
 * The primary read-execute-print loop. Once calls, runs until interrupted.
 * 
 * @param msh_envp The cloned environment that is shared across the shell
 * @return int Error return value (not used).
 */
int	repl(char ***msh_envp)
{
	int	last_exit;

	last_exit = 0;
	while (1)
	{
		repl_once(msh_envp, &last_exit);
	}
}
