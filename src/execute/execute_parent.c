/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:16:39 by tday              #+#    #+#             */
/*   Updated: 2024/04/13 19:46:12 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	close_fds(t_cmd *cmd_data)
{
	if (cmd_data->in_fd != STDIN_FILENO)
		close(cmd_data->in_fd);
	if (cmd_data->out_fd != STDOUT_FILENO)
		close(cmd_data->out_fd);
}

static void	free_exec_arrays(char **env, char **arg)
{
	if (!env || !arg)
		return ;
	free_array((void **)env);
	free(arg);
}

void	execute_parent(t_msh *msh, t_cmd *cmd_data)
{
	char	**env;
	char	**arg;
	t_list	*new_node;
	int		*pid;

	env = convert_envvar_to_array(msh);
	arg = put_args_in_array(cmd_data);
	pid = safe_calloc(1, sizeof(int), "execute_parent pid calloc error");
	*pid = fork();
	if (*pid < 0)
		msh_error_exit(msh, "exec_parent fork error");
	else if (*pid == 0)
		execute_child(msh, env, arg, cmd_data);
	new_node = lst_new_node(pid);
	if (!new_node)
		msh_error_exit(msh, "exec_parent new_node error");
	lst_add_tail(&msh->pids, new_node);
	close_fds(cmd_data);
	free_exec_arrays(env, arg);
}
