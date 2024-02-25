/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:04:46 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 20:04:25 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * @brief	determine whether a given string is a valid flag string
 *
 * @param 	str: the query string.
 * @return 	1 if the string is a valid flag
 * @return 	0 if not.
*/
int	is_valid_flag_word(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief  write arguments to the standard output
 *
 * The echo utility writes any specified operands, separated by single blank 
 * (` ') characters and followed by a newline (`\n') character, to the standard 
 * output. *
 *
 * [Optional flags] : -n : Do not print the trailing newline character
 *
 * @param char **args The arguments of our call 
 * @param char **envv a valid environmental variable array.
 * @return 0 on successful execution
 * @return >0 if an error occurs.
 *
*/
int	builtin_echo(char **args, char ***envp)
{
	int	i;
	int	newline;

	(void)envp;
	newline = 1;
	if (!args[1])
		return (printf("\n"), 0);
	i = 1;
	if (args[i] && is_valid_flag_word(args[i]))
	{
		newline = 0;
		while (args[i] && is_valid_flag_word(args[i]))
			i++;
	}
	while (args[i])
	{
		write(1, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
	return (0);
}
