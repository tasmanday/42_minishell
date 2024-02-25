/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:13 by lxu               #+#    #+#             */
/*   Updated: 2022/02/15 16:09:16 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define BUFFER_SIZE 256

typedef struct s_buff
{
	int				fd;
	char			*str;
	struct s_buff	*next;
}	t_buff;

char	*get_next_line(int fd);

t_buff	*new_buff(void);
t_buff	*get_buff(t_buff **list_of_buffers_head, int fd);
void	remove_buff(t_buff **list_of_buffers_head, int fd);

#endif
