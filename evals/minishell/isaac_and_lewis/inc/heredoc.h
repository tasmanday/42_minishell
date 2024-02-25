/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:15:29 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:33:33 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft.h"
# include "lexer.h"
# include "parameter_expansion.h"
# include "filename_expansion.h"
# include "split.h"
# include "signal.h"
# include "read.h"
# include "redirection.h"

/*		heredoc.c*/
int		enter_heredoc(char *delimiter, char **envv, int last_exit,
			int *heredoc_fd);
int		enter_heredocs(t_deque d, char **envv, int last_exit);

/*		heredoc1.c*/
int		fab(char *str);
int		guib_init(int *was_quoted, char *delimiter);
void	guib_do(char *line, char **envv, int last_exit, int write_buff);
int		gui_tobuff(char *delimiter, char **envv, int last_exit, int write_buff);

#endif
