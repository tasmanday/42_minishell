/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:46:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 12:01:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*s1 - *--s2);
}
