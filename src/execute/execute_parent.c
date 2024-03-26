/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:16:39 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 14:51:07 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	int		exit_status; // move later

	env = convert_envvar_to_array(msh);
	arg = put_args_in_array(cmd_data);
	pid = safe_calloc(1, sizeof(int), "execute_parent pid calloc error");
	*pid = fork();
	if (*pid < 0)
		msh_error_exit(msh, "exec_parent fork error");
	else if (*pid == 0)
		execute_child(msh, env, arg);
	waitpid(*pid, &exit_status, 0); // move later
	new_node = lst_new_node(pid);
	if (!new_node)
		msh_error_exit(msh, "exec_parent new_node error");
	lst_add_tail(&msh->pids, new_node);
	free_exec_arrays(env, arg);
}
