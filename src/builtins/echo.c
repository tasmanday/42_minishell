/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:13:56 by tday              #+#    #+#             */
/*   Updated: 2024/03/21 19:20:23 by tday             ###   ########.fr       */
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
	a helper function that checks for new line flags and updates the current
	token pointer in the linked list to be the first non new line flag token.

	Inputs
	[t_list **] curr_token: a pointer to the current token in the linked list.
	[bool *] print_newline: a pointer to a boolean variable that indicates
		whether a new line should be printed.

	Outputs
	none.
*/
static void	check_for_nl_flags(t_list **curr_arg, bool *print_newline)
{
	while (*curr_arg && (*curr_arg)->data && \
		is_nl_flag((char *)(*curr_arg)->data))
	{
		*print_newline = false;
		*curr_arg = (*curr_arg)->next;
	}
}

/*
	Summary
	prints the tokens stored in a linked list to the standard output.
	it also adds a space between tokens except for the last one.

	Inputs
	[t_list *] curr_token: a pointer to the current token in the linked list.

	Outputs
	none. the function prints the tokens stored in the linked list to the
	standard output. Each token is printed as a string, with a space between
	tokens except for the last one.
*/
static void	print_tokens(t_list *curr_arg)
{
	while (curr_arg && (char *)curr_arg->data)
	{
		ft_printf("%s", (char *)curr_arg->data);
		curr_arg = curr_arg->next;
		if (curr_arg && (char *)curr_arg->data)
			ft_printf(" ");
	}
}

/*
	Summary
	replicates the echo command by printing given argument strings to the
	standard output. also checks for a new line flag (-n) and handles it
	as echo would.

	Inputs
	[t_msh *] msh: the main struct of minishell contianing a linked	list of
		strings from the user imput that are separated into relevant tokens.

	Outputs
	prints the given strings to the standard output.
*/
void	ft_echo(t_dlist *curr_cmd)
{
	bool	print_newline;
	t_cmd	*cmd_struct;

	cmd_struct = (t_cmd *)curr_cmd->data;
	print_newline = true;
	if (!cmd_struct->arguments)
	{
		ft_printf("\n");
		return ;
	}
	check_for_nl_flags(&(cmd_struct->arguments), &print_newline);
	print_tokens(cmd_struct->arguments);
	if (print_newline)
		ft_printf("\n");
}
