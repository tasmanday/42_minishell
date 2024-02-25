/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_from_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:01:45 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 18:18:28 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	get_tokens_from_input(t_msh *msh, char **argv)
{
	int		i;

	i = 1; // skips ./minishell

	while (argv[i])
	{
		add_tokens_to_list(msh, argv[i]);
		i++;
	}
}
