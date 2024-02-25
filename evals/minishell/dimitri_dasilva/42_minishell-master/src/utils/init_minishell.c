/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:58:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/17 19:01:51by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_minishell.h"

/*
** Set a few things the program needs to run
** @param:	- [t_msh *] main struct of the program
**			- [char **] environment pointers that we need to duplicate
** Line-by-line comments:
** @1-2		Makes sure that the terminal is linked to the STDIN
** @6		Increases SHLVL environment variable everytime we call 
** 			./minishell inside another one
*/

/*
	Tas explanation

	if (!isatty(STDIN_FILENO)) checks if the standard input is a terminal,
		quits the program if it is not.

	ft_bzero(g_msh, sizeof(t_msh)); allocates memory for g_msh struct (short for
	minishell) this is the main struct of the program similar to data in fdf.
	used as a global variable.

	duplicate_env(&g_msh->dup_envp, envp); duplicates the envp string array
	creating temporary environment variables that it can be manipulated
	throughout the minishell program.

	unset_oldpwd(); the OLDPWD (old print wroking directory) is a variable
	that stores the previous working directory and updates when the working
	directory changes. this allows toggling back and forth with 'cd ..' for
	example. it should start unset when the program begins as there shouldn't
	be a previous working directory when at start. this function creates the
	oldpwd if it doesn;t exist or clears it if it already has a value.

	increment_shlvl(); increments the shell level. this is used to keep track
	of how deep you are in nested shell sessions.

	init_termcaps(&g_msh->termcaps); initialises and configures terminal
	capabilities for the shell program. this includes features such as
	cursor movement, text coloring, screen clearing, and more.

	signal(SIGINT, catch_sigint); sets up the signal handler for SIGINT.
	SIGINT is the signal sent to a program when the interrupt key
	(Ctrl+C or Ctrl+D) is pressed. catch_sigint prints a '\n' in this
	program.

	signal(SIGQUIT, catch_sigquit); sets up the signal handler for SIGQUIT.
	SIGQUIT is the signal sent to a program when the quit key (Ctrl+\) is
	pressed. catch_sigquit prints out quit message and kills children
	processes.
*/
void	init_minishell(t_msh *g_msh, char **envp)
{
	if (!isatty(STDIN_FILENO))
		quit_program(EXIT_FAILURE);
	ft_bzero(g_msh, sizeof(t_msh));
	duplicate_env(&g_msh->dup_envp, envp);
	unset_oldpwd();
	increment_shlvl();
	init_termcaps(&g_msh->termcaps);
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, catch_sigquit);
}
