/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:06 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 20:10:22 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term.h"

/**
 * @brief ensures ctrl-c, ctrl-\ do not print outside of process during readline
*/
void	setup_term(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag = t.c_lflag & ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

/**
 * @brief enables ctrl-c, ctrl-\ to print inside of process'/blocks (eg cat)
*/
void	reset_term(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag = t.c_lflag | ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}
