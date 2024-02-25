/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:05:41 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 16:35:40 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include "lexer.h"
# include "libft.h"
# include "utils.h"

/*		split.c*/
void	split_words(t_deque *tokens);
void	split_token_nodes(t_deque *tokens);
t_deque	split_word(char *str);

/*		split1.c*/
void	split_word_do_s1(char *str, t_deque *result_pt, int *slow, int *fast);
void	split_word_do_s2(char str_fast, int *state);
void	split_word_do_s3(char str_fast, int *state);
void	split_word_init(int *slow, int *fast, int *state);

#endif
