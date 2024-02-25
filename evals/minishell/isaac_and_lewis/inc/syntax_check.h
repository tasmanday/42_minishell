/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:35 by lxu               #+#    #+#             */
/*   Updated: 2023/09/11 22:11:29 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_CHECK_H
# define SYNTAX_CHECK_H

# include "libft.h"
# include "source.h"
# include "lexer.h"

int		syntax_is_valid(t_deque tokens);

void	print_err_token_str(char *token_str);
void	update_bracket_count(t_dlist *node, int *open_brackets, int *state);
int		bracket_checks(t_token_node *token, int *open_brackets, int *state);
int		token_checks_1(t_token_node *token, t_token_node *next);
int		token_checks_2(t_token_node *token, t_token_node *next);
int		token_checks_3(t_token_node *token, t_token_node *next);
int		token_checks_4(t_token_node *token, t_token_node *next);
int		token_checks_5(t_token_node *token, t_token_node *next);

#endif