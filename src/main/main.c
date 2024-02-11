/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 21:50:26 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	if (argc != 1)
		error_exit("Incorrect number of arguments"); 
	(void)argv;
	(void)argc;
	t_dlist	*envar;

	envar = NULL;
	clone_envv_to_dlist(envv, &envar);
	ft_pwd(envar);
	return (0);
}
