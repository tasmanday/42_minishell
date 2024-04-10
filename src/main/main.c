/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/04/07 20:05:30 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	t_msh	*msh;
//	char	*input = NULL;

	(void)argv;
	if (argc != 1)
		error_exit("Incorrect number of arguments");
	msh = init_minishell(envv);
	while (1)
	{
		msh->input = get_input(msh);
		if (!msh->input)
			continue;
		if (msh->input && msh->input[0] == '1') // enter 1 to exit input loop, remove later
		{
			free(msh->input);
			break ;
		}
		process_input(msh);
		execute_commands(msh);
	//	debug("exit_status"); // remove
	//	debug_int(msh->last_exit_status); //remove
		msh->num_of_cmds = 0;
		if (msh->input)
			free(msh->input);
		free_input(msh);
	}
	reset_signal_handlers();
	free_everything(msh);
	return (0);
}
