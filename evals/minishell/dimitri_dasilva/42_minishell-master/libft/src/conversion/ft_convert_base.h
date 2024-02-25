/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:30:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 11:32:10 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_BASE_H
# define FT_CONVERT_BASE_H

# include "libft.h"

# define ASCII_OFFSET_OTHERS 55
# define LIMIT_BEFORE_OVERFLOW 1152921504606846976

static int	length_nbr(unsigned long long nbr, char *base);
static void	ft_putnbr_base(unsigned long long nbr,
				char *base,
				char *nbr_converted);
static void	convert(unsigned long long nbr,
				char *base,
				int base_size,
				char *nbr_converted);

#endif
