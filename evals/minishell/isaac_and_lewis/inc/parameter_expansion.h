/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:43:10 by lxu               #+#    #+#             */
/*   Updated: 2023/09/12 22:43:59 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETER_EXPANSION_H
# define PARAMETER_EXPANSION_H

// # include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "lexer.h"

char	*make_expanded_string(char *str, char **envv, int last_exit);
void	expand_tokens(t_deque tokens, char **envv, int last_exit);

/*		parameter_expansion1.c*/
void	mes_do_1(char **str_pt, size_t *i, size_t *j, char **result_pt);
void	mes_do_2(size_t *i, size_t *j, char *found_parameter, char *env_key);
void	mes_do_3(char **str_pt, size_t *i, size_t *j, char **result_pt);
void	mes_init(size_t *i, size_t *j, size_t *state, char **result);

#endif
