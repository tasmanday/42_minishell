/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:56:04 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 15:57:11 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filename_expansion.h"

int	str_match_while_check(char comp1, char comp2, char comp3)
{
	if (comp1 && comp2 && comp1 == comp2
		&& (comp3 == '0' || comp2 != '*'))
		return (1);
	return (0);
}

void	it_slow_pat(size_t *slow, size_t *pattern_i)
{
	*slow = *slow + 1;
	*pattern_i = *pattern_i + 1;
}

int	str_matches_pattern_recursive_subcall(char *str, char *pattern, char *mask)
{
	size_t	slo;
	size_t	fast;
	size_t	pattern_i;

	slo = 0;
	fast = 0;
	pattern_i = 0;
	while (str_match_while_check(str[slo], pattern[pattern_i], mask[pattern_i]))
		it_slow_pat(&slo, &pattern_i);
	if (str[slo] == '\0' && pattern[pattern_i] == '\0')
		return (1);
	if (pattern[pattern_i] != '*' || mask[pattern_i] == '0')
		return (0);
	if (pattern[pattern_i + 1] == '\0')
		return (1);
	fast = slo;
	while (str[fast])
	{
		if (str_matches_pattern_recursive_subcall(
				&(str[fast]), &(pattern[pattern_i + 1]),
				&(mask[pattern_i + 1])))
			return (1);
		fast++;
	}
	return (0);
}

/**
 * @brief Boolean check to see if a string is a valid glob match for the pattern
 *
 * Glob matching following the rules for * operator provided by bash. A * can be
 * replaced by zero or more of any character.
 *
 * Pattern may contain any number of * char. Each * can represent zero or more
 * of any character in the str string.
 *
 * Masking of active/inactive asterisk (outside or inside of quotes) to handle
 * degenerate cases like *"foo" and "f*o" (matches foo, does not match foo)
 *
 * @param str The string to be checked.
 * @param pattern The pattern to be matched to.
 */
int	str_matches_pattern(char *str, char *pattern)
{
	char	*unquoted_pattern;
	char	*mask;
	int		result;

	mask = generate_pattern_active_mask(pattern);
	unquoted_pattern = ft_strdup(pattern);
	remove_quotes_string(unquoted_pattern);
	result = str_matches_pattern_recursive_subcall(str, unquoted_pattern, mask);
	free(mask);
	free(unquoted_pattern);
	return (result);
}
