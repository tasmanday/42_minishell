/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/03/01 16:36:38 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	//if (argc != 1)
	//	error_exit("Incorrect number of arguments"); 
	(void)argc;
	t_msh	*msh;
	char	*input = NULL;

	msh = safe_malloc(sizeof(t_msh), "msh malloc error");
	msh->envvar = NULL;
	msh->tokens = NULL;
	init_minishell(msh, argv, envv);
//	ft_echo(msh);
//	ft_env(msh);
//	ft_pwd(msh);
	debug("working up to loop");
	while (1)
	{
		debug("loop started");
		input = get_input(msh, "prompt: ");
		if (input[0] == '1')
			break;
		ft_printf("input: %s\n", input);
		free(input);
	}
	free_everything(msh);
//	debug("free_everything successful");
	return (0);
}
