/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:42:59 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:12:32 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	Toggles the print_paths flag.

	Inputs
	[t_msh *] msh: Pointer to the main minishell structure.

	Outputs
	None. Toggles the print_paths flag in the minishell.
*/
void	print_paths(t_msh *msh)
{
	if (msh->print_paths == true)
		msh->print_paths = false;
	else
		msh->print_paths = true;
}
