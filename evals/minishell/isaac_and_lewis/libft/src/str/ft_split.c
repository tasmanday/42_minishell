/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:54:35 by lxu               #+#    #+#             */
/*   Updated: 2022/01/11 03:48:20 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	destroy_table(char **table, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (table[i])
			free(table[i]);
		i++;
	}
	free(table);
}

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	number_of_words;

	number_of_words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			number_of_words++;
		}
		i++;
	}
	return (number_of_words);
}

static int	fill_table(char const *s, char c, char **table)
{
	size_t	table_i;
	size_t	i;
	size_t	word_length;

	table_i = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			word_length = 0;
			while (s[i + word_length] != c && s[i + word_length] != '\0')
				word_length++;
			table[table_i] = ft_strslice(s, i, i + word_length);
			if (!table[table_i])
				return (1);
			table_i++;
			i += word_length;
		}
	}
	table[table_i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	number_of_words;
	char	**words_table;
	int		error;

	number_of_words = word_count(s, c);
	words_table = malloc(sizeof (*words_table) * (number_of_words + 1));
	if (!words_table)
		return (NULL);
	error = fill_table(s, c, words_table);
	if (error)
	{
		destroy_table(words_table, number_of_words + 1);
		return (NULL);
	}
	return (words_table);
}
