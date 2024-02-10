/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:36:18 by tday              #+#    #+#             */
/*   Updated: 2024/02/10 18:09:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	allocates memory and returning a substring from the input_str based on
	the delimeter character.

	Inputs
	input_str = The original string from which the substring is extracted.
	delimeter = The character used as a delimiter to split the string.
	start_pos = A pointer to an integer that keeps track of the current position
	in the input_str.

	Outputs
	word = the substring extracted from the input string.

static char	*allocate_word(const char *input_str, char delimeter, \
int *start_pos)
{
	char	*word;
	int		length;
	int		word_index;

	length = 0;
	while ((input_str[*start_pos + length] != '\0') && \
	(input_str[*start_pos + length] != delimeter))
	{
		length++;
	}
	word = (char *) malloc((length + 1) * sizeof(char));
	if (!word)
		return (error("ft_split allocate_word malloc error"), NULL);
	word_index = 0;
	while ((input_str[*start_pos] != '\0') && \
	(input_str[*start_pos] != delimeter))
	{
		word[word_index] = input_str[*start_pos];
		word_index++;
		(*start_pos)++;
	}
	word[word_index] = '\0';
	return (word);
} */

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
static int	find_delimeter(const char *input_str, char delimeter)
{
	int		i;

	i = 0;
	while (input_str[i] != '\0')
	{
		if (input_str[i] == delimeter)
			return (i);
		i++;
	}
	return (0);
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
	delimeter = delimiter character used to split the string.

	Outputs
	result = array of substrings.
*/

//***** fix this so it creates an empty array if the first char is the delimeter
char	**ft_split_first(const char *input_str, char delimeter)
{
	char	**result;
	int		length;
	int		first_delimeter;
	int		word_count;
	int		current_word;

	current_word = 0;
	word_count = 1;
	first_delimeter = find_delimeter(input_str, delimeter);
	if (first_delimeter)
		word_count = 2;
	result = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (error("ft_split malloc error"), NULL);
	if (word_count == 2)
	{
		result[current_word] = ft_substr(input_str, 0, first_delimeter);
		if (!result[current_word])
			return (free_allocated(result, current_word), NULL);
		current_word++;
	}
	if (input_str[first_delimeter] == delimeter)
		first_delimeter++;
	length = ft_strlen(input_str + first_delimeter);
	result[current_word] = ft_substr(input_str, first_delimeter, length);
	if (!result[current_word])
		return (free_allocated(result, current_word), NULL);
	result[current_word + 1] = NULL;
	return (result);
}
