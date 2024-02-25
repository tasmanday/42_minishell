/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 15:07:48 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	//if (argc != 1)
	//	error_exit("Incorrect number of arguments"); 
	(void)argc;
	t_msh	*msh;

	msh = safe_malloc(sizeof(t_msh), "msh malloc error");
	msh->envvar = NULL;
	msh->tokens = NULL;
	init_minishell(msh, argv, envv);
//	ft_echo(msh);
//	ft_env(msh);
//	ft_pwd(msh);
	return (0);
}
