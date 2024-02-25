/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmakaran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:01:01 by wmakaran          #+#    #+#             */
/*   Updated: 2023/08/14 20:07:38 by wmakaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>

// Libft functions
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

// Pipex functions
void	ft_free_strs(char **strs);
void	ft_error(char *str);
void	ft_custom_error(char *s1, char *s2);
char	**ft_env_paths(char *envp[]);
char	*ft_cmd_path(char *cmd, char **paths);
int		ft_execute(char *full_cmd, char **paths, int fd_in, int fd_out);

#endif
