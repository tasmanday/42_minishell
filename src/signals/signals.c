/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:37:43 by sentry            #+#    #+#             */
/*   Updated: 2024/04/14 18:36:16 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	(Ctrl+C) handle_interrupt() handles SIGINT signal to write a new line, move 
	the readline cursor to a new line, replace the current line with an empty 
	string and redisplays the prompt if standard input is a terminal 
	(isatty(STDIN_FILENO)==1). If stdin is not a terminal, do nothing.

	Inputs
	[int sig] signal number (void) not used.

	Outputs
	None.
*/
void	handle_interrupt(int sig)
{
	(void)sig;
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*
	Summary
	(CTRL-\) handle_quit() checks if the standard input is a terminal 
	(isatty(STDIN_FILENO)==1). If yes, the SIGQUIT(CTRL-\) signal is 
	ignored by setting to SIG_IGN and the the shell continues to run as usual as 
	fn does nothing (as CTRL-\ is supposed to).

	Inputs
	[int sig] signal number (void) not used.

	Outputs
	None.
*/
void	handle_quit(int sig)
{
	if (isatty(STDIN_FILENO))
	{
		(void)sig;
		signal(SIGQUIT, SIG_IGN);
	}
	return ;
}

/*
	Summary 
	(CTRL+C and CTRL-\) setup_signal_handlers() registers signal handlers for 
	SIGINT(CTRL+C) to interrupt the current command being run by the shell, 
	and SIGQUIT(CTRL-\) to quit the shell.

	Inputs
	None.

	Outputs
	None.
*/
void	setup_signal_handlers(void)
{
	signal(SIGINT, handle_interrupt);
	signal(SIGQUIT, handle_quit);
}

/*
	Summary
	(CTRL+C and CTRL-\) reset_signal_handlers() resets signal handlers 
	for SIGINT(CTRL+C) and SIGQUIT(CTRL-\) to defaults. This means that:
	- SIGINT: the process is terminated immediately
	- SIGQUIT: the process terminates with a core dump

	Inputs
	None.

	Outputs
	None.
*/
void	reset_signal_handlers(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
