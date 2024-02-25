/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:18:09 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:23:52 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"

/**
 * @brief handles the Ctrl-C key combination (SIGINT signal) 
 * exclusively outside of process'
 *
 * @param sig the signal being received.
 */
void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/**
 * @brief reset the signal handlers to the behaviour required at readline/ 
 * outside of process', emulating bash behaviour.
 *
 * sets the SIGINT handler to our sig_handler function above.
 * ignores the SIGQUIT signal.
 */
void	sig_initialiser_during_read(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

/**
 * @brief handles the Ctrl-C key combination (SIGINT signal) 
 * to be called exclusively inside a process/ fork.
 *
 * @param sig the signal being received.
 */
void	sig_handler_inpc(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

/**
 * @brief handles the Ctrl-\ key combination (SIGQUIT signal) 
 * to be called exclusively inside a process/ fork.
 *
 * @param sig the signal being received.
 */
void	sig_quit_handler_inpc(int sig)
{
	char	*temp;

	if (sig == SIGQUIT)
	{
		temp = ft_itoa(sig);
		if (!temp)
			return ;
		write(2, "Quit: ", 6);
		write(2, temp, ft_strlen(temp));
		write(2, "\n", 1);
		free(temp);
	}
}

void	sig_initialiser_during_execute(void)
{
	signal(SIGINT, sig_handler_inpc);
	signal(SIGQUIT, sig_quit_handler_inpc);
}
