/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:53:35 by sentry            #+#    #+#             */
/*   Updated: 2024/04/14 15:07:18 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	get_new_path() gets the path to the new directory to change to. It gets the
	cwd() and checks if there are any arguments. If there are no arguments, it
	changes the directory to the HOME directory. If there is a "." argument, it
	changes the directory to the current directory. If there is a ".." argument,
	it changes the directory to the parent directory. Otherwise, it changes the
	directory to the directory specified by the argument. Memory for the cwd is
	freed, then the new path is returned.

	Inputs
	[t_cmd *] cmd_struct: the command struct containing the arguments.

	Outputs
	A new string with the new path.
*/

static char	*get_new_path(t_cmd	*cmd_struct)
{
	char	*path;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cmd_struct->arguments)
		path = ft_strdup(getenv("HOME"));
	else if (ft_strcmp(cmd_struct->arguments->data, ".") == 0)
		path = ft_strdup(cwd);
	else if (ft_strcmp(cmd_struct->arguments->data, "..") == 0)
		path = NULL;
	else
		path = ft_strdup(cmd_struct->arguments->data);
	free(cwd);
	return (path);
}

/*
	Summary
	update_env_vars() updates the environment variables "PWD" and "OLDPWD" to
	reflect the current working directory and the previous working directory.
	fn() iterates through the list of environment variables, and for each 
	environment variable, it checks if the key is "PWD". If it is, it
	updates the value of the environment variable to the new current working
	directory.
	After updating the "PWD" variable, the fn() calls find_envvar_node() to 
	find the node in the list of environment variables that has the key "OLDPWD".
	update_node_value() is then called to update the value of the "OLDPWD" 
	variable to the old working directory.
 
	Inputs
	[t_msh *] msh: the main struct of minishell.
	[char *] old_pwd: the old working directory.
	[char *] new_pwd: the new working directory.

	Outputs
	None.
 */
static void	update_env_vars(t_msh	*msh, char	*old_pwd, char	*new_pwd)
{
	t_dlist	*current;
	t_envv	*env_var;

	current = msh->envvar;
	while (current)
	{
		env_var = (t_envv *)current->data;
		if (ft_strcmp(env_var->env_key, "PWD") == 0)
		{
			free(env_var->env_value);
			env_var->env_value = ft_strdup(new_pwd);
		}
		current = current->next;
	}
	update_node_value(find_envvar_node(msh->envvar, "OLDPWD"), old_pwd);
}

/*
	Summary
	free_resources() frees the resources allocated by ft_cd() by freeing
	the path (if not NULL) and the old_pwd (if not NULL).
 
 	Inputs
 	[char *] path: the path to the new working directory.
 	[char *] old_pwd: the old working directory.

	Outputs
	None.
 */

static void	free_resources(char *path, char *old_pwd)
{
	if (path && path != NULL)
	{
		free(path);
	}
	if (old_pwd && old_pwd != NULL)
	{
		free(old_pwd);
	}
}

/*
	Summary
	free_and_return() frees the resources allocated by ft_cd() by
	freeing the path (if not NULL) and the old_pwd (if not NULL).
	It then returns the integer return_value.

	Inputs
	[char *] path: the path to the new working directory.
	[char *] old_pwd: the old working directory.
	[int] return_value: the integer to return.

	Outputs
 	return_value.
 */

static int	free_and_return(char	*path, char	*old_pwd, int return_value)
{
	if (path && path != NULL)
	{
		free(path);
	}
	if (old_pwd && old_pwd != NULL)
	{
		free(old_pwd);
	}
	return (return_value);
}

/*
	Summary
	ft_cd mimics the builtin cd command to change the current working directory.
	If the command has more than one argument, an error is printed and 
	returns (1). If the new path to the new working directory doesn't exist, 
	an error is printed and returns (1). If there is no argument, fn() changes 
	to the parent directory. If there was an error getting the old working 
	directory or there was an error changing to the new working directory, 
	fn() frees the resources and returns (1). If there was an error getting the 
	new working directory, fn() free the resources and returns (1). Environment 
	variables PWD and OLDPWD are updated, resources are freed, and successful
	exit status of 0 is returned.

	Inputs
	[t_msh *] msh: the main struct of minishell.
	[t_cmd *] cmd_struct: the command struct containing the arguments.

	Outputs
	Exit status of the builtin.
*/

int	ft_cd(t_msh *msh, t_cmd *cmd_struct)
{
	char	cwd[PATH_MAX];
	char	*old_pwd;
	char	*path;
	char	*new_pwd;

	if (cmd_struct->arguments && cmd_struct->arguments->next != NULL)
		return (handle_too_many_args());
	path = get_new_path(cmd_struct);
	if (path && access(path, F_OK) != 0)
	{
		perror("");
		return (free_and_return(path, NULL, 1));
	}
	if (!path && chdir("..") != 0)
		return (1);
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd || (path && chdir(path) != 0))
		return (free_and_return(path, old_pwd, 1));
	new_pwd = getcwd(cwd, sizeof(cwd));
	if (!new_pwd)
		return (free_and_return(path, old_pwd, 1));
	update_env_vars(msh, old_pwd, new_pwd);
	free_resources(path, old_pwd);
	return (0);
}

/*
static void	free_resources(char *path, char *old_pwd)
{
	if (path && path != NULL)
	{
		free(path);
	}
	if (old_pwd && old_pwd != NULL)
	{
		free(old_pwd);
	}
}

static int	free_and_return(char	*path, char	*old_pwd)
{
	free_resources(path, old_pwd);
	return (1);
}

//OG
int	ft_cd(t_msh	*msh, t_cmd *cmd_struct)
{
	char	cwd[PATH_MAX];
	char	*old_pwd;
	char	*new_pwd;
	char	*path;

	if (cmd_struct->arguments && cmd_struct->arguments->next != NULL)
	{
		ft_printf("cd: too many arguments\n");
		return (1);
	}
	path = get_new_path(cmd_struct);
	if (path && access(path, F_OK) != 0)
	{
		perror("");
		free_resources(path, NULL);
		return (1);
	}
	if (!path && chdir("..") != 0)
		return (1);
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		free_and_return(path, old_pwd);
	if (path)
	{
		if (chdir(path) != 0)
			free_and_return(path, old_pwd);
	}
	new_pwd = getcwd(cwd, sizeof(cwd));
	if (!new_pwd)
		free_and_return(path, old_pwd);
	update_env_vars(msh, old_pwd, new_pwd);
	free_resources(path, old_pwd);
	return (0);
}
*/
