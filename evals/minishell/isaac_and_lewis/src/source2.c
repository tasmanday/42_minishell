/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:25:54 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 13:31:25 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

/**
 * @brief Skips internal field separator characters.
 *
 * Internal field separator characters (IFS) as specified by bash are (only):
 * space char
 * tab char (\t)
 * new line char (\n)
 * These values are hardcoded in this function. It move the pos pointer forward
 * until it sees a character that isn't an IFS.
 */
void	skip_internal_field_separators(t_source *src)
{
	while ((src->buff)[src->pos] != '\0' \
		&& ft_isinstr((src->buff)[src->pos], " \t\n"))
	{
		src->pos += 1;
	}
}

/**
 * @brief Boolean operator that tells us if the next char(s) are an operator.
 *
 * Valid operators are as listed in the operator enum.
 * NB. & char followed by another char is considered "not an operator" as we
 * are explictly not asked to only handle && (and not &) as an operator.
 * 
 * @return 1 (bool true) if next char(s) are an operator
 * @return 0 (bool false) if next char(s) are not an operator
 */
int	operator_is_next(t_source *src)
{
	char	c;
	char	d;

	c = peek_char(src);
	d = peek_peek_char(src);
	if (!c)
		return (0);
	if (c == d && d == '&')
		return (1);
	if (ft_isinstr(c, "|()<>"))
		return (1);
	return (0);
}

/**
 * @brief Takes a double char length operator if possible.
 *
 * Takes a two character length operator from the current position of the source
 * Returns None (NONE_OPERATOR) if it is unable to do so.
 *
 * @return The next two character operator (if possible).
 * @return NONE_OPERATOR if unable to take a double operator.
 */
enum e_operator	take_double_operator(t_source *src)
{
	char			c;
	char			d;
	enum e_operator	op;

	c = peek_char(src);
	d = peek_peek_char(src);
	op = NONE_OPERATOR;
	if (!c || !d)
		return (NONE_OPERATOR);
	if (c == d && d == '<')
		op = DOUBLE_LESS_THAN;
	if (c == d && d == '>')
		op = DOUBLE_GREATER_THAN;
	if (c == d && d == '&')
		op = DOUBLE_AND;
	if (c == d && d == '|')
		op = DOUBLE_PIPE;
	if (op != NONE_OPERATOR)
	{
		src->pos += 2;
		return (op);
	}
	return (NONE_OPERATOR);
}

/**
 * @brief Takes a single char length operator if possible.
 *
 * Takes a one character length operator from the current position of the source
 * Returns None (NONE_OPERATOR) if it is unable to do so.
 *
 * Note: This does not check to see if it could have taken a two char operator.
 * Ie if the next two characters are || it will take the first | and leave the
 * next char. It is reliant on preferentially trying to take a double operator
 * first.
 *
 * @return The next one character operator (if possible).
 * @return NONE_OPERATOR if unable to take a double operator.
 */
enum e_operator	take_single_operator(t_source *src)
{
	char			c;
	enum e_operator	op;

	c = peek_char(src);
	op = NONE_OPERATOR;
	if (!c)
		return (NONE_OPERATOR);
	if (c == '|')
		op = PIPE;
	if (c == '(')
		op = LEFT_BRACKET;
	if (c == ')')
		op = RIGHT_BRACKET;
	if (c == '<')
		op = LESS_THAN;
	if (c == '>')
		op = GREATER_THAN;
	if (op != NONE_OPERATOR)
	{
		src->pos += 1;
		return (op);
	}
	return (NONE_OPERATOR);
}

/**
 * @brief Takes a operator if possible
 *
 * Takes a operator from the current position in the source if possible. Does so
 * with a greedy strategy. Tries to take a double operator first if possible,
 * ten if it can't, tries to take a single operator.
 *
 * @return The next operator (if possible).
 * @return NONE_OPERATOR if unable to take a operator.
 */
enum e_operator	take_operator(t_source *src)
{
	enum e_operator	op;

	op = NONE_OPERATOR;
	op = take_double_operator(src);
	if (op != NONE_OPERATOR)
	{
		return (op);
	}
	op = take_single_operator(src);
	if (op != NONE_OPERATOR)
	{
		return (op);
	}
	return (NONE_OPERATOR);
}
