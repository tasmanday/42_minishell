/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:00:50 by wmakaran          #+#    #+#             */
/*   Updated: 2023/07/28 15:07:54 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_n_putnbr_rec(long nbr)
{
	int		n;
	char	c;

	n = 0;
	if (nbr == 0)
		return (0);
	n += ft_n_putnbr_rec(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
	return (1 + n);
}

int	ft_n_putnbr(long nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
		return (1 + ft_n_putnbr_rec(nbr));
	}
	else
	{
		return (ft_n_putnbr_rec(nbr));
	}
}
