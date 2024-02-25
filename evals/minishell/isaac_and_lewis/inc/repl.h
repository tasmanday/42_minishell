/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:17:29 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:36:43 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPL_H
# define REPL_H

# include <stdio.h>
# include "libft.h"
# include "bool.h"
# include "read.h"
# include "source.h"
# include "lexer.h"
# include "syntax_check.h"
# include "heredoc.h"
# include "parameter_expansion.h"
# include "split.h"
# include "filename_expansion.h"
# include "quote_removal.h"
# include "parse.h"
# include "execute.h"
# include "redirection.h"
# include "debug.h"
# include "builtins.h"
# include "signal.h"
# include "term.h"
# include "shlvl.h"

int	repl(char ***msh_envp);

#endif
