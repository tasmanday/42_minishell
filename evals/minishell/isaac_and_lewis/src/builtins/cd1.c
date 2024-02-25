/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:31:34 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 20:02:18 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	cd2(char **args, char *temp_pwd)
{
	print_err("cd: %s: File name too long\n", args[1]);
	free (temp_pwd);
	return (1);
}

int	cd3(char **args, char *temp_pwd)
{
	print_err("cd: %s: Not a directory\n", args[1]);
	free (temp_pwd);
	return (1);
}

int	cd4(char *temp_pwd, char ***envp)
{
	update_both_envvs(temp_pwd, envp);
	free(temp_pwd);
	return (0);
}

int	cd5(char *temp_pwd, char **args)
{
	print_err("msh: cd: %s: Permission denied\n", args[1]);
	free(temp_pwd);
	return (1);
}

int	cd6(char *temp_pwd, char **args)
{
	print_err("msh: cd: %s: ", args[1]);
	perror("");
	free(temp_pwd);
	return (1);
}
