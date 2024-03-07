/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:23:16 by tday              #+#    #+#             */
/*   Updated: 2024/03/06 22:21:25 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	export_no_args(msh)
{
	t_dlist	*curr_variable;
	t_envv	*data;

	curr_variable = msh->envvar;
	while (curr_variable)
	{
		data = (t_envv *)curr_variable->data;
		if (data->value == NULL)
			ft_printf("declare -x %s\n", data->key);
		else
			ft_printf("declare -x %s=\"%s\"\n", data->key, data->value);
}

void	ft_export(t_msh *msh)
{
	t_list	*curr_token;
	char	*command;
	char	**var_array;

	curr_token = msh->tokens;
	command = (char *)curr_token->data;
	if (command == "export" && !curr_token->next)
		export_no_args(msh); // write function to handle export with no arguments
	else if (command == "export" && curr_token->next)
		export_args(msh); // write function to handle export with arguments
}
