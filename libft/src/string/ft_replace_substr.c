/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_substr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:06:16 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 16:09:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	**** ALLOCATES MEMORY ****
	memory is allocated for the returned string 'new_str'.

	Summary
	replaces a substring in a string with another substring.

	Inputs
	[char *] str: the original string.
	[int] start: the starting index of the substring to be replaced.
	[int] end: the ending index of the substring to be replaced.
	[char *] substr: the substring to replace the original substring with.

	Outputs
	[char *] new_str: the resulting string after replacement.
*/
char	*ft_replace_substr(char *str, int start, int end, char *substr)
{
	char	*pre_substr;
	char	*post_substr;
	char	*new_str;

	pre_substr = ft_substr(str, 0, start);
	post_substr = ft_substr(str, end, (ft_strlen(str) - end));
	new_str = ft_strjoin_any(3, pre_substr, substr, post_substr);
	free(pre_substr);
	free(post_substr);
	return (new_str);
}
