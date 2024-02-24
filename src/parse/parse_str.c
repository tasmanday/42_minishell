/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:20:37 by tday              #+#    #+#             */
/*   Updated: 2024/02/24 13:20:37 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


// possibly redundant
/* void	parse_str(t_dlist *envvar, char **str)
{
	int	i;

	i = 0;
	while (str[0][i])
	{
		if (str[0][i] == '$')
			expand_envvar(envvar, str, &i);
		i++;
	}
}
*/