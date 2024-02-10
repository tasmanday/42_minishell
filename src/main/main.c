/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/02/10 17:58:51 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//int	main(int argc, char **argv, char **envv)
int	main(void)
{
	/*if (argc != 1)
		error_exit("Incorrect number of arguments"); 
	(void)argv;
	(void)argc;
	//(void)envv; // remove later when duplicating envv
	t_dlist	*env_dlist;

	env_dlist = NULL;
	clone_envv_to_dlist(envv, &env_dlist);
	// write function for freeing allocated memory from clone_envv_to_dlist 
	return (ft_env(env_dlist)); */

	char	**array;
	char	*string = "====key=value";
	int		i;

	i = 0;
	array = ft_split_first(string, '=');
	while (array[i])
	{
		ft_printf("array[%i]: %s\n", i, array[i]);
		i++;
	}
	return (0);
}
