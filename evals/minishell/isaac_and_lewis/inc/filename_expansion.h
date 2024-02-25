/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:43:34 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:33:16 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILENAME_EXPANSION_H
# define FILENAME_EXPANSION_H

# include "libft.h"
# include "lexer.h"
# include "quote_removal.h"
# include "utils.h"
# include <dirent.h>

/*		filename_expansion.c*/
void	filename_expansion(t_deque *tokens);
t_deque	filename_expand_word(char *str);
int		str_matches_pattern(char *str, char *pattern);

/*		filename_expansion1.c*/
int		compare_strings_helper(void *s1, void *s2);
void	set_state_it_i(int set_state, int *i, int *state);
void	set_mask_it_i_j(char set_mask, int *i, int *j, char *mask);
void	gpam_do(char *pattern, int *state, int *it, char *mask);
char	*generate_pattern_active_mask(char *pattern);

#endif
