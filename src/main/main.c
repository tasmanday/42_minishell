/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/03/11 23:35:48 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	t_msh	*msh;
	char	*input = NULL;

	(void)argv;
	if (argc != 1)
		error_exit("Incorrect number of arguments");
	msh = init_minishell(envv);
	while (1)
	{
		input = get_input(msh, "prompt: ");
		if (!input || input[0] == '\0')
		{
			free(input);
			continue ;
		}
		if (input[0] == '1') // enter 1 to exit input loop
		{
			free(input);
			break ;
		}
		add_tokens_to_list(msh, input);
		extract_commands(msh);
//		debug("extract_commands complete");
		t_cmd	*cmd_struct = (t_cmd *)msh->cmd_queue->data;
		if (ft_strcmp(cmd_struct->command, "env") == 0)
			ft_env(msh);
		if (ft_strcmp(cmd_struct->command, "pwd") == 0)
			ft_pwd(msh);
		if (ft_strcmp(cmd_struct->command, "export") == 0)
			ft_export(msh);
		if (ft_strcmp(cmd_struct->command, "echo") == 0)
			ft_echo(msh);
		if (msh->cmd_queue)
		{
			dlst_del_all(&(msh->cmd_queue), free_cmd_struct);
			msh->cmd_queue = NULL;
		}
		if (msh->tokens)
		{
			debug("still tokens");
			lst_del_all(&(msh->tokens), free_string);
			msh->tokens = NULL;
		}
		free(input);
	}
	free_everything(msh);
//	debug("free_everything successful");
	return (0);
}
