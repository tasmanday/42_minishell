/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:22:07 by tday              #+#    #+#             */
/*   Updated: 2024/01/14 23:22:07 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* 
	Summary
	writes the given integer to the standard output (terminal) as a string of
	characters.

	Inputs
	nb = integer number.

	Outputs
	none.
 */
void	ft_putnbr(int nb)
{
	if (nb > -2147483648 || nb <= 2147483647)
	{
		if (nb == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		else if (nb < 0)
		{
			nb *= -1;
			ft_putchar('-');
			ft_putnbr(nb);
		}
		else if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
		{
			ft_putchar('0' + nb);
		}
	}
}
