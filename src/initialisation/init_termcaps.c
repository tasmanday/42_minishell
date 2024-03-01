/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:40:25 by tday              #+#    #+#             */
/*   Updated: 2024/03/01 16:36:26 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_termcaps(t_msh *msh)
{
	char	*term_value;

	if (tcgetattr(STDIN_FILENO, &msh->termcaps->original_term) == -1)
		clean_exit(msh, EXIT_FAILURE);
	term_value = get_env_value(msh->envvar, "TERM");
	if (!term_value)
		clean_exit(msh, EXIT_FAILURE);
	if (tgetent(msh->termcaps->buffer, term_value) <= 0)
		clean_exit(msh, EXIT_FAILURE);
	// check capabilities
}
