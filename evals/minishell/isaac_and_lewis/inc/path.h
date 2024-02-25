/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:34:20 by lxu               #+#    #+#             */
/*   Updated: 2023/09/06 18:55:16 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "utils.h"
# include <sys/stat.h>
# include "builtins.h"

char	*get_path(char *cmd, char **env);
int		is_directory(const char *path);
char	*command_search(char *str, char ***envp);
char	*get_pathpos(char *cmd, char **env);

#endif
