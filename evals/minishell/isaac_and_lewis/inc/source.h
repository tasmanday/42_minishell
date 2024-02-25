/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:30:05 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:38:49 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# include <stdio.h>
# include "libft.h"
# include "utils.h"

typedef struct s_source {
	char	*buff;
	size_t	buff_size;
	size_t	pos;
}	t_source;

// REF: https://www.gnu.org/software/bash/manual/bash.html#Definitions
// A control operator..
//     || && | ( )    (others & ; ;; ;& ;;& |& are not handled as per spec)
// ...or a redirection operator
//     << >> < >    (others are not handled as per our project spec)
enum e_operator {
	NONE_OPERATOR,
	DOUBLE_PIPE,
	DOUBLE_AND,
	PIPE,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	DOUBLE_LESS_THAN,
	DOUBLE_GREATER_THAN,
	LESS_THAN,
	GREATER_THAN,
};

t_source		*new_source(char *buff);
void			delete_source(t_source *src);
char			take_char(t_source *src);
char			peek_char(t_source *src);
char			peek_peek_char(t_source *src);

void			skip_internal_field_separators(t_source *src);
int				operator_is_next(t_source *src);
enum			e_operator	take_operator(t_source *src);
char			*take_word(t_source *src);
int				quotes_valid(char *str);

char			*take_word_do1(char *result, t_source *src, size_t end);
void			take_word_do2(t_source *src, int *state, size_t *end);
void			take_word_do_state2(t_source *src, int *state, size_t *end);
void			take_word_do_state3(t_source *src, int *state, size_t *end);
int				take_word_check1(t_source *src, size_t end);

#endif
