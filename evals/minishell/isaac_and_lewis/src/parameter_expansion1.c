/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:40:42 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/12 22:43:39 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameter_expansion.h"

void	mes_do_1(char **str_pt, size_t *i, size_t *j, char **result_pt)
{
	char	*tmp_str;

	tmp_str = ft_strslice(*str_pt, *i, *j);
	ft_strappend(result_pt, tmp_str);
	free(tmp_str);
}

void	mes_do_2(size_t *i, size_t *j, char *found_parameter, char *env_key)
{
	free(found_parameter);
	*j = *j + ft_strlen(env_key);
	*i = *j;
	free(env_key);
	*j = *j - 1;
}

void	mes_do_3(char **str_pt, size_t *i, size_t *j, char **result_pt)
{
	char	*tmp_str;

	tmp_str = ft_strslice(*str_pt, *i, *j);
	ft_strappend(result_pt, tmp_str);
	free(tmp_str);
}

void	mes_init(size_t *i, size_t *j, size_t *state, char **result)
{
	*i = 0;
	*j = 0;
	*state = 1;
	*result = ft_strdup("");
}
