/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:06:28 by tday              #+#    #+#             */
/*   Updated: 2024/03/01 14:34:13 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_everything(t_msh *msh)
{
	if (msh)
	{
		if (msh->envvar)
		{
			dlst_del_all(&(msh->envvar), free_envv_struct);
			msh->envvar = NULL;
		}
		if (msh->tokens)
		{
			lst_del_all(&(msh->tokens), free_string);
			msh->tokens = NULL;
		}
		free(msh);
	}
}
