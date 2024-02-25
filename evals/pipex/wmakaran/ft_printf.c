/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:21:45 by wmakaran          #+#    #+#             */
/*   Updated: 2023/07/28 15:13:46 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_printf_decision(char *ptr, va_list ap)
{
	int		n;

	n = 0;
	if (*ptr == 'c')
		n += ft_n_putchar(va_arg(ap, int));
	if (*ptr == 's')
		n += ft_n_putstr(va_arg(ap, char *));
	if (*ptr == 'p')
		n += ft_n_putpointer(va_arg(ap, void *));
	if (*ptr == 'd')
		n += ft_n_putnbr(va_arg(ap, int));
	if (*ptr == 'i')
		n += ft_n_putnbr(va_arg(ap, int));
	if (*ptr == 'u')
		n += ft_n_putnbr(va_arg(ap, unsigned int));
	if (*ptr == 'x')
		n += ft_n_puthex(va_arg(ap, int));
	if (*ptr == 'X')
		n += ft_n_puthex_upper(va_arg(ap, int));
	if (*ptr == '%')
		n += ft_n_putchar('%');
	return (n);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n;
	char	*ptr;

	ptr = (char *)fmt;
	n = 0;
	va_start(ap, fmt);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			n += ft_printf_decision(ptr, ap);
		}
		else
			n += ft_n_putchar(*ptr);
		ptr++;
	}
	va_end(ap);
	return (n);
}
