/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:13:56 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 20:22:20 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	static function to check if a string is a valid new line flag (-n) for the
	echo command. to ba valid the string must start with a '-' followed by one
	or more occurences of 'n'.

	Inputs
	[char *} str: a pointer to a string that represents either a new line flag
	or a word top be printed.

	Outputs
	true if the given string is a valid new line flag for the echo command.
	false if it's not.
*/
static bool	is_nl_flag(char *str)
{
	int		i;

	if (!str || !str[0])
		return (false);
	if (str[0] != '-')
		return (false);
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

/*
	Summary
	replicates the echo command by printing given strings to the standard output.
	also checks for a new line flag (-n) and handles it as echo would.

	Inputs
	[char **] argv: an array of strings passed to the ft_echo function.

	Outputs
	prints the given strings to the standard output.
	returns 0 to represent successfully completing the function. this will
	possibly be replaced with void when implementing as part of minishell.
*/
int	ft_echo(char **argv)
{
	int		i;
	bool	newline_flag;

	newline_flag = true;
	if (!argv[1])
		return (ft_printf("\n"), 0);
	i = 1;
	while (argv[i] && is_nl_flag(argv[i]))
	{
		newline_flag = false;
		i++;
	}
	while (argv[i])
	{
		ft_printf("%s", argv[i]);
		i++;
		if (argv[i])
			ft_printf(" ");
	}
	if (newline_flag)
		ft_printf("\n");
	return (EXIT_SUCCESS);
}
