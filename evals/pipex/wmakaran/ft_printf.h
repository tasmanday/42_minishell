/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:24:39 by wmakaran          #+#    #+#             */
/*   Updated: 2023/07/28 15:01:49 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *fmt, ...);

int	ft_n_putchar(char c);
int	ft_n_putstr(char *str);
int	ft_n_putpointer(void *ptr);
int	ft_n_putnbr(long nbr);
int	ft_n_puthex(unsigned int nb);
int	ft_n_puthex_upper(unsigned int nb);

#endif
