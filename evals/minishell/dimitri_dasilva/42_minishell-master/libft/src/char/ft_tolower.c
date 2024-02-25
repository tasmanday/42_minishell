/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:37:38 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 12:03:44 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UPPERCASE_OFFSET 32

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + UPPERCASE_OFFSET);
	else
		return (c);
}
