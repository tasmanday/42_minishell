/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envv_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:25:10 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 19:50:59 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_envv_struct(void *data)
{
	t_envv	*envv;

	envv = (t_envv *)data;
	if (envv)
	{
		free(envv->env_key);
		free(envv->env_value);
		free(envv);
	}
}
