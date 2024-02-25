/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:12:01 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 11:27:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_power(long long nb, long long power)
{
	long long	result;

	if (power == 0)
		return (1);
	else if (power <= 0)
		return (0);
	result = 1;
	while (power--)
		result *= nb;
	return (result);
}
