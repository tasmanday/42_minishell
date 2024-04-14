/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:23:46 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	Entry point for the minishell program. Initializes the minishell,
	enters a loop to read and process user input, executes commands,
	and cleans up resources before exiting.

	Inputs
	[int] argc: Number of command-line arguments.
	[char **] argv: Array of command-line arguments.
	[char **] envv: Array of environment variables.

	Outputs
	[int] 0 if successful.
*/
int	main(int argc, char **argv, char **envv)
{
	t_msh	*msh;

	(void)argv;
	if (argc != 1)
		error_exit("Incorrect number of arguments");
	msh = init_minishell(envv);
	while (1)
	{
		msh->input = get_input(msh);
		if (ft_strcmp(msh->input, "") == 0)
			continue ;
		process_input(msh);
		execute_commands(msh);
		msh->num_of_cmds = 0;
		free_input(msh);
	}
	reset_signal_handlers();
	free_everything(msh);
	return (0);
}
