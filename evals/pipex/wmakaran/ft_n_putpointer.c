/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_putpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:39:59 by wmakaran          #+#    #+#             */
/*   Updated: 2023/07/28 14:55:15 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_n_puthex_rec(unsigned long nb)
{
	char	c;
	int		n;

	if (nb == 0)
		return (0);
	n = ft_n_puthex_rec(nb / 16);
	if (nb % 16 < 10)
		c = (nb % 16) + '0';
	else
		c = (nb % 16) - 10 + 'a';
	write(1, &c, 1);
	return (n + 1);
}

static int	ft_n_puthex(unsigned long nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (ft_n_puthex_rec(nb));
}

int	ft_n_putpointer(void *ptr)
{
	unsigned long	address;
	int				n;

	address = (unsigned long)(ptr);
	write(1, "0x", 2);
	n = 2 + ft_n_puthex(address);
	return (n);
}
