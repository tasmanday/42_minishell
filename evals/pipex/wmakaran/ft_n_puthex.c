/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_putpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:39:59 by wmakaran          #+#    #+#             */
/*   Updated: 2023/07/28 14:54:36 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_n_puthex_rec(unsigned int nb)
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

int	ft_n_puthex(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (ft_n_puthex_rec(nb));
}

static int	ft_n_puthex_rec_upper(unsigned int nb)
{
	char	c;
	int		n;

	if (nb == 0)
		return (0);
	n = ft_n_puthex_rec_upper(nb / 16);
	if (nb % 16 < 10)
		c = (nb % 16) + '0';
	else
		c = (nb % 16) - 10 + 'A';
	write(1, &c, 1);
	return (n + 1);
}

int	ft_n_puthex_upper(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (ft_n_puthex_rec_upper(nb));
}
