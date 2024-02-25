/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:24:09 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:19:35 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"

/**
 * @brief Suppress signal.
 * 
 * @param sig The signal number that is received.
 */
void	sig_quiet(int sig)
{
	(void)sig;
}

/**
 * @brief Suppress signals.
 * 
 * Used to suppress signals during some child processes (intermediary processes)
 * 
 * Eg, when using pipe, child processes are used for each side. The parent is
 * still monitoring for signals and doing the terminal printing. And the running
 * processes still respond to the signal and will exit with value. The
 * intermediary processes should not do anyting special. They will expect to
 * take the exit value from the running commands and bubble it back up to the
 * parent process. Therefore, they need to have their signal responses
 * suppressed.
 */
void	sig_initialiser_do_nothing(void)
{
	signal(SIGINT, sig_quiet);
	signal(SIGQUIT, sig_quiet);
}

/**
 * @brief Parent handling of signal while entering a heredoc.
 * 
 * @param sig The signal being received
 */
void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

/**
 * @brief Signal handling during a heredoc
 * 
 * The parent signal handling behaviour during a heredoc
 */
void	sig_initialiser_during_heredoc(void)
{
	signal(SIGINT, sig_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

/**
 * @brief Signal handling behaviour of child process when entering heredoc
 * 
 */
void	sig_initialiser_during_heredoc_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}
