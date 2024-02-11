/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:07:23 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 18:53:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	allocates memory and returning a substring from the input_str based on
	the delimiter character.

	Inputs
	input_str = The original string from which the substring is extracted.
	delimiter = The character used as a delimiter to split the string.
	start_pos = A pointer to an integer that keeps track of the current position
	in the input_str.

	Outputs
	word = the substring extracted from the input string.
*/
static char	*allocate_word(const char *input_str, char delimiter, \
int *start_pos)
{
	char	*word;
	int		length;
	int		word_index;

	length = 0;
	while ((input_str[*start_pos + length] != '\0') && \
	(input_str[*start_pos + length] != delimiter))
	{
		length++;
	}
	word = (char *) malloc((length + 1) * sizeof(char));
	if (!word)
		return (error("ft_split allocate_word malloc error"), NULL);
	word_index = 0;
	while ((input_str[*start_pos] != '\0') && \
	(input_str[*start_pos] != delimiter))
	{
		word[word_index] = input_str[*start_pos];
		word_index++;
		(*start_pos)++;
	}
	word[word_index] = '\0';
	return (word);
}

/*
	Summary
	counts the number of words in a given string, based on a specified
	delimiter character.

	Inputs
	input_str = The original string to count the words from.
	delimiter = The character used as a delimiter to separate the words.

	Outputs
	count = the number of words in the input string.
*/
static int	count_words(const char *input_str, char delimiter)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (input_str[i] != '\0')
	{
		while (input_str[i] == delimiter && input_str[i] != '\0')
			i++;
		if (input_str[i] != delimiter && input_str[i] != '\0')
		{
			count++;
			while (input_str[i] != delimiter && input_str[i] != '\0')
				i++;
		}
	}
	return (count);
}

/*
	Summary
	frees the memory allocated for the array of substrings.

	Inputs
	result = A double pointer to the array of substrings.
	j = An integer representing the index of the last substring in the array.

	Outputs
	none.
*/
static void	free_allocated(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
}

/*
	Summary
	allocates memory and returns an array of substrings obtained by splitting
	the original using the character ’delimeter’ as a delimiter.
	the array must end with a NULL pointer.

	Inputs
	input_str = original string.
	delimiter = delimiter character used to split the string.

	Outputs
	result = array of substrings.
*/
char	**ft_split(const char *input_str, char delimiter)
{
	char	**result;
	int		i;
	int		current_word;
	int		word_count;

	i = 0;
	current_word = 0;
	word_count = count_words(input_str, delimiter);
	result = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (error("ft_split malloc error"), NULL);
	while (input_str[i] != '\0' && current_word < word_count)
	{
		while (input_str[i] == delimiter)
			i++;
		result[current_word] = allocate_word(input_str, delimiter, &i);
		if (!result[current_word])
		{
			free_allocated(result, current_word);
			return (NULL);
		}
		current_word++;
	}
	result[current_word] = NULL;
	return (result);
}
