/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:49:04 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 11:52:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*sav_d;

	sav_d = dest;
	while (*dest)
		dest++;
	while (nb && *src)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (sav_d);
}
