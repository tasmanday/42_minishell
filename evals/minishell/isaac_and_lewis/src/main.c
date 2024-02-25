/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:58:34 by lxu               #+#    #+#             */
/*   Updated: 2023/09/11 17:51:46 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envv)
{
	char	**msh_envv;

	(void)argv;
	msh_envv = msh_clone_envv(envv);
	msh_update_shlvl(&msh_envv);
	if (argc != 1)
	{
		print_err("Incorrect number of args. Exiting\n");
		exit(1);
	}
	repl(&msh_envv);
}
