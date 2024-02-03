/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:44:28 by tday              #+#    #+#             */
/*   Updated: 2024/01/28 14:15:43 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
	Summary
	function does nothing. can be used for functions that need a function as a
	paramter.
*/
void	no_op(void *arg)
{
	(void)arg;
}
