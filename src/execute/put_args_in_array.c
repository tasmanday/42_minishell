/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_args_in_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:10:09 by tday              #+#    #+#             */
/*   Updated: 2024/03/23 17:28:16 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**put_args_in_array(t_cmd *cmd_struct)
{
	char	**array;
	t_list	*args;
	int		i;
	int		length;

	args = cmd_struct->arguments;
	length = lst_size(args);
	array = safe_calloc(length + 2, sizeof(char *), \
		"put_args_in_array error");
	array[0] = (char *)cmd_struct->command;
	i = 1;
	while (i <= length)
	{
		array[i++] = (char *)args->data;
		args = args->next;
	}
	return (array);
}
