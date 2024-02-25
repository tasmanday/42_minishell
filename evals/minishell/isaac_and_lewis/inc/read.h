/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:59:27 by lxu               #+#    #+#             */
/*   Updated: 2023/09/11 19:21:01 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# define PS1 "msh-0.1$ "
# define PS2 "> "

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "utils.h"

void	free_char_array(char **arr);
char	*msh_readline(char *prompt, char **envv, int *last_exit_ptr);

#endif
