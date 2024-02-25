/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:33:44 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 21:26:59 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "builtins.h"

/**
 * @brief trims back a string by 1 character, freeing the old string. 
 *
 * @param 	str the subject string.
*/
char	*msh_remove_char(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i - 1] = '\0';
	free(str);
	return (new_str);
}

/**
 * @brief	sets a new environmental variable from our env_str argument-
 * 			assuming it is correctly formatted. 
 *  
 * @param 	char *env_str the contents of our new environmental variable.
 * @param 	char ***envp ptr to a valid environmental variable array.
 * @return 	0 on successful execution
 * @return 	>0 if an error occurs.
*/
int	msh_concatenv(char *env_str, char ***envp, char *env_val)
{
	char	**key_value;
	char	**envv;
	char	**new_envv;
	int		i;

	envv = *envp;
	new_envv = malloc(sizeof(char *) * (get_array_height(*envp) + 2));
	key_value = NULL;
	if (env_str == NULL || env_str[0] == '\0')
		return (1);
	key_value = ft_split(env_str, '=');
	if (!key_value)
		return (1);
	if (get_array_height(key_value) > 2)
		return (free_char_array(key_value), 1);
	i = -1;
	while (envv[++i])
		new_envv[i] = ft_strdup(envv[i]);
	key_value[0] = msh_remove_char(key_value[0]);
	new_envv[i] = ft_strconcat(4, key_value[0], "=", env_val, key_value[1]);
	new_envv[++i] = NULL;
	free_char_array(*envp);
	*envp = new_envv;
	return (free_char_array(key_value), 0);
}

int	print_caller(int i, char **args)
{
	print_err("msh: line %d: export: ", i);
	print_err("`%s': not a valid identifier\n", args[i]);
	return (1);
}

int	builtin_export_do(char **args, char ***envp, int i, int *ret)
{
	char	*env_name;
	char	*env_value;

	env_name = envv_to_key(*envp, args[i], is_valid_concat_exp(args[i]));
	env_value = NULL;
	if (env_name)
	{
		env_value = msh_getenv(*envp, env_name);
		if (!env_value)
			*ret += 1;
	}
	if (env_value != NULL && unset_caller(env_name, envp))
		return (1);
	if (is_valid_concat_exp(args[i]))
		msh_concatenv(args[i], envp, env_value);
	else
		msh_setenv(args[i], envp);
	free(env_name);
	free(env_value);
	return (0);
}

/**
 * @brief  sets a new environmental variable, or overwrites
 * an existing variable withing envv.
 *
 * @param char **args The arguments of our call 
 * @param char ***envp ptr to a valid environmental variable array.
 * @return 0 on successful execution
 * @return >0 if an error occurs.
*/
int	builtin_export(char **args, char ***envp)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if (!args[1] || args[1][0] == '\0')
		return (print_export_env(args, *envp));
	while (args[i])
	{
		if (ft_strrchr((const char *)args[i], '='))
		{
			if (!(is_valid_eq_exp(args[i]) || is_valid_concat_exp(args[i])))
				ret += print_caller(i, args);
			else if (builtin_export_do(args, envp, i, &ret))
				return (1);
		}
		else if (!export_arg_neq_check(args[i]))
			ret += print_caller(i, args);
		else
			msh_setenv(args[i], envp);
		i++;
	}
	if (ret > 0)
		return (1);
	return (0);
}
