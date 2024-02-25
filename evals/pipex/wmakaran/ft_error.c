/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:27:52 by wmakaran          #+#    #+#             */
/*   Updated: 2023/08/14 18:39:24 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_error(char *str)
{
	char	*full_str;

	if (!str)
	{
		perror("\033[31mError");
	}
	else
	{
		full_str = ft_strjoin("\033[31mError: ", str);
		perror(full_str);
		free(full_str);
	}
	exit(-1);
}

void	ft_custom_error(char *s1, char *s2)
{
	if (!s2)
		ft_printf("\033[31mError: %s\n", s1);
	else
		ft_printf("\033[31mError: %s: %s\n", s1, s2);
	exit(-1);
}
