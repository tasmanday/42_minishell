#include "../../inc/minishell.h"

void	ft_unset(t_msh *msh)
{
	t_cmd	*cmd_struct;
	t_list	*args;
	t_dlist	*env_node;

	cmd_struct = (t_cmd *)msh->cmd_queue->data;
	if (!cmd_struct->arguments)
		return ;
	else
	{
		args = cmd_struct->arguments;
		while (args)
		{
			env_node = find_envvar_node(msh->envvar, (char *)args->data);
			if (!env_node)
			{
				args = args->next;
				continue ;
			}
			dlst_del_node(&msh->envvar, env_node, free_envv_struct);
			args = args->next;
		}
	}
}
