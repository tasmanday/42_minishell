/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:53:35 by sentry            #+#    #+#             */
/*   Updated: 2024/03/24 10:57:49 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
// WORKING FT_CD (testing for handling of absolute and relative pathing)
void ft_cd(t_msh *msh)
{
    char cwd[PATH_MAX];
    t_cmd *cmd_struct;
    char *path;

    cmd_struct = (t_cmd *)msh->cmd_queue->data;
    if (!cmd_struct->arguments)
    {
        char *home_dir = getenv("HOME");
        if (home_dir == NULL)
        {
            fprintf(stderr, "cd: HOME directory not set\n");
            return;
        }
        path = home_dir;
    }
    else
        path = cmd_struct->arguments->data;
    if (chdir(path) != 0)
    {
        perror("cd");
        return;
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        return;
    }
    t_dlist *current = msh->envvar;
    while (current)
    {
        t_envv *env_var = (t_envv *)current->data;
        if (ft_strcmp(env_var->env_key, "PWD") == 0)
        {
            free(env_var->env_value);
            env_var->env_value = ft_strdup(cwd);
            if (env_var->env_value == NULL)
            {
                perror("strdup");
                return;
            }
            break;
        }
        current = current->next;
    }
    printf("%s\n", cwd);
}
*/

/*
// WORKING CD but doesn't update old pwd
void	ft_cd(t_msh	*msh)
{
	char	cwd[PATH_MAX];
	t_cmd	*cmd_struct;
	char	*path;
	t_dlist	*current;
	char	*home_dir;
	t_envv	*env_var;

	cmd_struct = (t_cmd *)msh->cmd_queue->data;
	if (!cmd_struct->arguments)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			printf("cd: HOME directory not set\n");
			return ;
		}
		path = ft_strdup(home_dir);
		if (path == NULL)
		{
			perror("strdup");
			return ;
		}
	}
	else
	{
		path = ft_strdup(cmd_struct->arguments->data);
		if (path == NULL)
		{
			perror("strdup");
			return ;
		}
	}
	old_pwd = getenv("PWD");
	if (chdir(path) != 0)
	{
		perror("cd");
		free(path);
		return ;
	}
	if (old_pwd != NULL)
		setenv("OLDPWD", old_pwd, 1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		free(path);
		return ;
	}
	current = msh->envvar;
	while (current)
	{
		env_var = (t_envv *)current->data;
		if (ft_strcmp(env_var->env_key, "PWD") == 0)
		{
			free(env_var->env_value);
			env_var->env_value = ft_strdup(cwd);
			if (env_var->env_value == NULL)
			{
				perror("strdup");
				free(path);
				return ;
			}
			break ;
		}
		current = current->next;
	}
	printf("%s\n", cwd);
	free(path);
}
*/

/*
void	ft_cd(t_msh	*msh)
{
	char	cwd[PATH_MAX];
	t_cmd	*cmd_struct;
	char	*path;
	t_dlist	*current;
	char	*home_dir;
	t_envv	*env_var;

	cmd_struct = (t_cmd *)msh->cmd_queue->data;
	if (!cmd_struct->arguments)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			printf("cd: HOME directory not set\n");
			return ;
		}
		path = ft_strdup(home_dir);
		if (path == NULL)
		{
			perror("strdup");
			return ;
		}
	}
	else
	{
		path = ft_strdup(cmd_struct->arguments->data);
		if (path == NULL)
		{
			perror("strdup");
			return ;
		}
	}
	old_pwd = getenv("PWD");
	if (chdir(path) != 0)
	{
		perror("cd");
		free(path);
		return ;
	}
	if (old_pwd != NULL)
	//	setenv("OLDPWD", old_pwd, 1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		free(path);
		return ;
	}
	current = msh->envvar;
	while (current)
	{
		env_var = (t_envv *)current->data;
		if (ft_strcmp(env_var->env_key, "PWD") == 0)
		{
			free(env_var->env_value);
			env_var->env_value = ft_strdup(cwd);
			if (env_var->env_value == NULL)
			{
				perror("strdup");
				free(path);
				return ;
			}
			break ;
		}
		current = current->next;
	}
	printf("%s\n", cwd);
	free(path);
}
*/

void ft_cd(t_msh *msh)
{
    char cwd[PATH_MAX];
    t_cmd *cmd_struct;
    char *path;
    t_dlist *current;
    char *home_dir;
    t_envv *env_var;
    t_dlist *oldpwd_node = find_envvar_node(msh->envvar, "OLDPWD");
	char *old_pwd;
	char *new_pwd;

    cmd_struct = (t_cmd *)msh->cmd_queue->data;
    if (!cmd_struct->arguments)
    {
        home_dir = getenv("HOME");
        if (home_dir == NULL)
        {
            printf("cd: HOME directory not set\n");
            return;
        }
        path = ft_strdup(home_dir);
        if (path == NULL)
        {
            perror("strdup");
            return;
        }
    }
    else
    {
        path = ft_strdup(cmd_struct->arguments->data);
        if (path == NULL)
        {
            perror("strdup");
            return;
        }
    }
    old_pwd = getcwd(NULL, 0);
    if (old_pwd == NULL)
    {
        perror("getcwd");
		free(path);
        return;
    }
    if (chdir(path) != 0)
    {
        perror("cd");
        free(path);
		free(old_pwd);
        return;
    }
    new_pwd = getcwd(cwd, sizeof(cwd));
    if (new_pwd == NULL)
    {
        perror("getcwd");
        free(path);
		free(old_pwd);
        return;
    }
    current = msh->envvar;
    while (current)
    {
        env_var = (t_envv *)current->data;
        if (ft_strcmp(env_var->env_key, "PWD") == 0)
        {
            free(env_var->env_value);
            env_var->env_value = ft_strdup(new_pwd);
            if (env_var->env_value == NULL)
            {
                perror("strdup");
                free(path);
                return;
            }
        }
        current = current->next;
    }
    if (oldpwd_node)
    {
        update_node_value(oldpwd_node, old_pwd);
    }
    printf("%s\n", cwd);
    free(path);
	free(old_pwd);
}
