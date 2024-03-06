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