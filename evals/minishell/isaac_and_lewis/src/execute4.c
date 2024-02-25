/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:54:09 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 12:55:15 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	fde(t_command *cmd, char *path_str)
{
	print_err("msh_internal: failed to malloc space for args array\n");
	free(path_str);
	delete_command(cmd);
	exit(1);
}

void	tecc_norm1(t_command *cmd, char *path_str, char **args)
{
	print_err("msh: %s: ", path_str);
	perror("");
	free(path_str);
	free_char_array(args);
	delete_command(cmd);
}
