/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:14:28 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 17:30:01 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdlib.h> 
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "libft.h"
# include "utils.h"

/*		builtin_execve.c */
int		is_builtin(char *cmd);
char	*builtin_command_search(char *cmd);
int		builtin_execve(char *cmd, char **args, char ***envp);

int		builtin_echo(char **args, char ***envp);
int		builtin_envv(char **args, char ***envp);
int		builtin_exit(char **args, char ***envp);
int		builtin_export(char **args, char ***envp);
int		builtin_pwd(char **args, char ***envp);	
int		builtin_unset(char **args, char ***envp);	

/* 		builtin_utils.c*/
char	*get_lowercase_str(char *str);
int		is_builtin_cmd(char *str);
void	free_ar_til(char **arr, int n);
void	ft_swap(char **str1, char **str2);
int		get_array_height(char **str_array);

/* 		cd.c*/
int		is_relative_path(char *str);
int		update_envv(char *dest, char *src, char ***envp);
int		update_both_envvs(char *temp_pwd, char ***envp);
int		cd1(char *home_path, char *temp_pwd, char ***envp);
int		builtin_cd(char **args, char ***envp);

/*		cd1.c*/
int		cd2(char **args, char *temp_pwd);
int		cd3(char **args, char *temp_pwd);
int		cd4(char *temp_pwd, char ***envp);
int		cd5(char *temp_pwd, char **args);
int		cd6(char *temp_pwd, char **args);

/*		testers.c*/
void	echo_tester(char **envv);

/* 		export1.c*/
char	**copy_str_array(char **str_array, int count);
int		print_export_env(char **args, char **envv);
char	**get_alpha_order(char **str_array);
int		unset_caller(char *env_name, char ***envp);

/*		export2.c*/
int		export_arg_neq_check(char *str);
int		is_valid_eq_exp(char *export_str);
int		is_valid_concat_exp(char *export_str);
int		msh_setenv1(char *env_str);
int		msh_setenv(char *env_str, char ***envp);

/*		get_env.c */
char	*ft_strndup(const char *str, size_t len);
char	*is_in_env(char **envv, const char *envVar);
char	*envv_to_key(char **envv, const char *envVar, int is_concat);
char	*msh_getenv(char **envv, const char *str);

#endif
