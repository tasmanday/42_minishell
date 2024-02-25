/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:21:21 by wmakaran          #+#    #+#             */
/*   Updated: 2023/07/16 16:18:24 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_parts(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		m;
	char	**output;

	output = (char **)malloc(sizeof(char *) * (get_parts(s, c) + 1));
	if (!output)
		return (NULL);
	m = 0;
	i = 0;
	while (m < get_parts(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		output[m] = (char *)malloc(sizeof(char) * (j + 1));
		j = 0;
		while (s[i] && s[i] != c)
			output[m][j++] = s[i++];
		output[m++][j] = '\0';
	}
	output[m] = NULL;
	return (output);
}

/*
#include <stdio.h>
int main()
{
	char **output;

	output = ft_split(" Hello  World ",' ');
	while (*output)
	{
		printf("%s\n",*output);
		output++;
	}
	return (0);
}
*/
