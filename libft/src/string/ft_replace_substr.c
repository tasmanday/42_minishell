/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_substr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:06:16 by tday              #+#    #+#             */
/*   Updated: 2024/02/25 21:39:33 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	copies the section of the string before the new substring.

	Inputs
	[char **] str: a pointer to a string that will be modified.
	[char *] temp: a pointer to a string that contains the characters to be
		copied.
	[int *] i: a pointer to an integer that keeps track of the current index in
		the str string.
	[int] start: an integer representing the index from which the characters
		should start being copied.
	
	Outputs
	none. The function modifies the str string by copying characters from the
	temp string before the specified start index.
*/
static void	copy_pre_substr(char **str, char *temp, int *i, int start)
{
	while (*i < start)
	{
		str[0][*i] = temp[*i];
		(*i)++;
	}
}

/*
	Summary
	copies a substring into a string starting from the current index.

	Inputs
	[char **] str: a pointer to a string where the substring will be copied
		into.
	[char *] substr: a pointer to the substring that will be copied.
	[int *] i: A pointer to the current index in str where the copying will
		start.

	Outputs
	none. The function modifies the string str in place.
*/
static void	copy_substr(char **str, char *substr, int *i)
{
	int	j;

	j = 0;
	while (substr[j])
	{
		str[0][*i] = substr[j];
		(*i)++;
		j++;
	}
}

/*
	Summary
	copies the section of the string after the removed substring placing them
	after the new substring characters.

	Inputs
	[char **] str: a pointer to a string that will be modified.
	[char *] temp: a pointer to a string that contains the characters to be
		copied.
	[int *] i: a pointer to an integer representing the current index in the str
		string.
	[int] end: an integer representing the index after which the characters
		should be copied.

	Outputs
	none. The function modifies the string str in place.
*/
static void	copy_post_substr(char **str, char *temp, int *i, int end)
{
	int	j;

	j = end + 1;
	while (temp[j])
	{
		str[0][*i] = temp[j];
		(*i)++;
		j++;
	}
	str[0][*i] = '\0';
}

/*
	Summary
	replaces a substring within a given string with another substring.

	Inputs
	[char **] str: a pointer to a string that will be modified.
	[int] start: the starting index of the substring to be replaced.
	[int] end: the ending index of the substring to be replaced.
	[char *] substr: the substring that will replace the original substring.

	Outputs
	none. The modified string is passed back through the str parameter.
*/
void	ft_replace_substr(char **str, int start, int end, char *substr)
{
	int		total_length;
	int		str_length;
	int		substr_length;
	int		i;
	char	*temp;

	temp = ft_strdup(*str);
	if (!temp)
		return ;
	str_length = ft_strlen(*str);
	substr_length = ft_strlen(substr);
	total_length = str_length + substr_length - (end - start) + 1;
	*str = ft_realloc(*str, str_length, total_length);
	if (!*str)
	{
		free(temp);
		return ;
	}
	i = 0;
	copy_pre_substr(str, temp, &i, start);
	copy_substr(str, substr, &i);
	copy_post_substr(str, temp, &i, end);
	free(temp);
}
