/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:14:11 by tday              #+#    #+#             */
/*   Updated: 2024/01/26 12:58:04 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
***************** this function does not free allocated memory ****************
*********** memory must be freed after this function to avoid leaks ***********

	Summary
	reads a line from a file descriptor and returns it as a string.
	It reads characters one by one until it encounters a newline character or
	reaches the end of the file.

	Inputs
	fd = an integer representing the file descriptor.
	
	Outputs
	returns next line as a dynamically allocated string.
***** dynamically allocated memory must be freed outside of this function *****
*/
char	*get_next_line(int fd)
{
	char	buffer;
	char	line[200000];
	int		bytes_read;
	int		i;

	if (fd < 0)
		return (NULL);
	i = 0;
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		bytes_read = read(fd, &buffer, 1);
	}
	line[i] = '\0';
	if (bytes_read <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(line));
}
