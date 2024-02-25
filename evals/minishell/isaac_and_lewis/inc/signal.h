/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:14:28 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:23:35 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h> 
# include "libft.h"

/*		signal.c*/
void	sig_quiet(int sig);
void	sig_initialiser_do_nothing(void);
void	sig_heredoc(int sig);
void	sig_initialiser_during_heredoc(void);
void	sig_initialiser_during_heredoc_child(void);

/*		signal1.c*/
void	sig_handler(int sig);
void	sig_initialiser_during_read(void);
void	sig_handler_inpc(int sig);
void	sig_quit_handler_inpc(int sig);
void	sig_initialiser_during_execute(void);

#endif
