/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:35:13 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:42:42 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shlvl.h"

/*
* @brief: NORM_HELPER
*/
void	msh_update_shlvl_do(char **shlvl_str_pt, int shlvl)
{
	print_err("msh: warning: shell level (%d) too high,", shlvl + 1);
	print_err(" resetting to 1\n");
	*shlvl_str_pt = ft_itoa(1);
}

/*
* @brief: Function for setting SHLVL envv prior to msh repl.
*/
void	msh_update_shlvl(char ***msh_envp)
{
	char	*shlvl_str;
	char	*args[3];
	int		shlvl;

	shlvl_str = msh_getenv(*msh_envp, "SHLVL");
	if (!shlvl_str || ft_strlen(shlvl_str) == 0)
		args[1] = ft_strdup("SHLVL=1");
	else
	{
		shlvl = ft_atoi(shlvl_str);
		free(shlvl_str);
		if (shlvl < 0)
			shlvl_str = ft_itoa(0);
		else if (shlvl > 999)
			msh_update_shlvl_do(&shlvl_str, shlvl);
		else
			shlvl_str = ft_itoa(shlvl + 1);
		args[1] = ft_strconcat(2, "SHLVL=", shlvl_str);
	}
	free(shlvl_str);
	args[0] = "export";
	args[2] = NULL;
	builtin_export(args, msh_envp);
	free(args[1]);
}
