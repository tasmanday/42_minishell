/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:45:26 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 15:51:15 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filename_expansion.h"

/**
 * @brief Void * wrapper for ft_strncmp to allow make it take a void * as param
 */
int	compare_strings_helper(void *s1, void *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}

/*
 * NORM_HELPER
*/
void	set_state_it_i(int set_state, int *i, int *state)
{
	*state = set_state;
	*i = *i + 1;
}

/*
 * NORM_HELPER
*/
void	set_mask_it_i_j(char set_mask, int *i, int *j, char *mask)
{
	mask[*j] = set_mask;
	*i = *i + 1;
	*j = *j + 1;
}

/*
 * NORM_HELPER
*/
void	gpam_do(char *pattern, int *state, int *it, char *mask)
{
	if (*state == 1)
	{
		if (pattern[it[0]] == '\"')
			set_state_it_i(2, &it[0], state);
		else if (pattern[it[0]] == '\'')
			set_state_it_i(3, &it[0], state);
		else
			set_mask_it_i_j('1', &it[0], &it[1], mask);
	}
	else if (*state == 2)
	{
		if (pattern[it[0]] == '\"')
			set_state_it_i(1, &it[0], state);
		else
			set_mask_it_i_j('0', &it[0], &it[1], mask);
	}
	else if (*state == 3)
	{
		if (pattern[it[0]] == '\'')
			set_state_it_i(1, &it[0], state);
		else
			set_mask_it_i_j('0', &it[0], &it[1], mask);
	}
}

char	*generate_pattern_active_mask(char *pattern)
{
	char	*mask;
	int		*it;
	int		state;
	char	*unquoted_string;

	unquoted_string = ft_strdup(pattern);
	remove_quotes_string(unquoted_string);
	mask = malloc(sizeof(char) * (ft_strlen(unquoted_string) + 1));
	it = malloc(sizeof(int) * 2);
	free(unquoted_string);
	if (!mask)
		return (NULL);
	it[0] = 0;
	it[1] = 0;
	state = 1;
	while (pattern[it[0]])
	{
		gpam_do(pattern, &state, it, mask);
	}
	mask[it[1]] = '\0';
	free(it);
	return (mask);
}
