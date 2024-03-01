/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:36:18 by tday              #+#    #+#             */
/*   Updated: 2024/03/01 14:31:50 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	finds the position of the delimiter charicter within a given string.

	Inputs
	[const char *] input_str = The given string to search.
	[char] delimiter = The character used as a delimiter to separate the words.

	Outputs
	the position of the delimiter within the array or 0 if there is no
	delimiter character present.
*/
static int	find_delimiter(const char *input_str, char delimiter)
{
	int		i;

	i = 0;
	while (input_str[i] != '\0')
	{
		if (input_str[i] == delimiter)
			return (i);
		i++;
	}
	return (0);
}

/*
	Summary
	frees the memory allocated for the array of substrings.

	Inputs
	[char **] result = A double pointer to the array of substrings.
	[int] i = An integer representing the index of the last substring in the
		array.

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
	handles the case when the delimiter is present within the string by
	creating a substring of the characters before the delimiter and storing
	them in the first string of the array

	Inputs
	[const char *] input_str: A pointer to the original string.
	[char **] result: A double pointer to the array of substrings.
	[int *] current_word: A pointer to an integer representing the index of the 
		current word in the array.
	[int] first_delimiter: An integer representing the position of the first
		delimiter character in the string.

	Outputs
	None. The function updates the result array with the first word of the string
	and increments the current_word index.
*/
static void	store_first_word(const char *input_str, char **result, \
	int *current_word, int first_delimiter)
{
	if (first_delimiter == 0)
	{
		result[*current_word] = ft_substr("", 0, 0);
		if (!result[*current_word])
		{
			free_allocated(result, *current_word);
			error_exit("ft_split_first > ft_substr malloc error");
		}
	}
	else
	{
		result[*current_word] = ft_substr(input_str, 0, first_delimiter);
		if (!result[*current_word])
		{
			free_allocated(result, *current_word);
			error_exit("ft_split_first > ft_substr malloc error");
		}
	}
	(*current_word)++;
}

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for the returned array of substrings.
	this will need to be freed later when it is no longer needed.

	Summary
	allocates memory and returns an array of substrings obtained by splitting
	the original using the first instance of the character ’delimeter’ as a
	delimiter.
	the array must end with a NULL pointer.

	Inputs
	[const char *] input_str = original string.
	[const char] delimiter = delimiter character used to split the string.

	Outputs
	result = array of substrings.
*/
char	**ft_split_first(const char *input_str, const char delimiter)
{
	char	**result;
	int		length;
	int		first_delimiter;
	int		word_count;
	int		current_word;

	current_word = 0;
	word_count = 1;
	first_delimiter = find_delimiter(input_str, delimiter);
	if (first_delimiter || input_str[0] == delimiter)
		word_count = 2;
	result = (char **) safe_malloc((word_count + 1) * sizeof(char *), \
		"ft_split_first malloc error");
	if (word_count == 2)
		store_first_word(input_str, result, &current_word, first_delimiter);
	if (input_str[first_delimiter] == delimiter)
		first_delimiter++;
	length = ft_strlen(input_str + first_delimiter);
	result[current_word] = ft_substr(input_str, first_delimiter, length);
	if (!result[current_word])
		return (free_allocated(result, current_word), NULL);
	result[current_word + 1] = NULL;
	return (result);
}
