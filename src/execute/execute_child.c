/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:48:33 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 20:48:33 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execute_child(t_msh *msh, char **env, char **arg)
{
	char	*path;

	if (has_path(arg[0]))
	{
		path = ft_strdup(arg[0]);
		if (!path)
			msh_error_exit(msh, "execute_child path error");
	}
	else
		path = get_path(arg[0]);
}