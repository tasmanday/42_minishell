/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:18:33 by tday              #+#    #+#             */
/*   Updated: 2024/01/21 16:40:27 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	compares two strings and returns an integer value based on the comparison
	result.

	Inputs
	s1: a pointer to the first string to be compared.
	s2: a pointer to the second string to be compared.

	Outputs
	Returns a negative integer if s1 is less than s2.
	Returns a positive integer if s1 is greater than s2.
	Returns 0 if s1 is equal to `s2.
*/
int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
