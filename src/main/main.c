/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 22:06:23 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	//if (argc != 1)
	//	error_exit("Incorrect number of arguments"); 
	(void)argc;
	t_msh	*msh;
//	t_dlist	*envvar;

//	envvar = NULL;
//	clone_envv_to_dlist(envv, &envvar);
	init_minishell(msh, argv, envv);
	ft_echo(envvar, argv); // put params in msh
	return (0);
}
