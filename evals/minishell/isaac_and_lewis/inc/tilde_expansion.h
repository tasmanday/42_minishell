/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:45 by lxu               #+#    #+#             */
/*   Updated: 2023/09/11 19:18:46 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILDE_EXPANSION_H
# define TILDE_EXPANSION_H

# include "libft.h"
# include "lexer.h"
# include "quote_removal.h"
# include "utils.h"

char	*tilde_expand_string(char *str, char **envv);
void	tilde_expand_tokens(t_deque tokens, char **envv);

#endif