/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:43:37 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:32:46 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft.h"
# include "stdio.h"
# include "errno.h"
# include "parse.h"
# include "redirection.h"
# include "path.h"
# include "builtins.h"
# include "signal.h"
# include "command.h"

int		do_command(t_ast_node *node, char ***envp, int last_exit);
int		do_brackets(t_ast_node *node, char ***envp, int last_exit);
int		do_pipe(t_ast_node *node, char ***envp, int last_exit);
int		do_and(t_ast_node *node, char ***envp, int last_exit);
int		do_or(t_ast_node *node, char ***envp, int last_exit);
int		do_ast_node(t_ast_node *node, char ***envp, int last_exit);

/*		execute.c*/
int		setup_fds(t_command *cmd);
int		setup_fds_and_backup(t_command *cmd, int *bup_fd_stdin,
			int *bup_fd_stdout);
int		revert_fds(int backup_fd_stdin, int backup_fd_stdout);
int		try_execute_builtin(t_command *cmd, char ***envp, int *ret,
			int last_exit);
int		do_command(t_ast_node *node, char ***envp, int last_exit);

/*		execute1.c*/
int		try_execute_command(t_command *cmd, char ***envp, int *ret,
			int last_exit);

/*		execute2.c*/
int		do_and(t_ast_node *node, char ***envp, int last_exit);
int		do_or(t_ast_node *node, char ***envp, int last_exit);
int		do_brackets(t_ast_node *node, char ***envp, int last_exit);

/*		execute3.c*/
int		do_pipe(t_ast_node *node, char ***envp, int last_exit);
int		do_ast_node(t_ast_node *node, char ***envp, int last_exit);

/*		execute4.c*/
void	fde(t_command *cmd, char *path_str);
void	tecc_norm1(t_command *cmd, char *path_str, char **args);

#endif
