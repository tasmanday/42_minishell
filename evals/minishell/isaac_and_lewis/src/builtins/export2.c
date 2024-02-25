/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:11:59 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 21:42:41 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_setenv1(char *env_str)
{
	char	**key_value;

	key_value = ft_split(env_str, '=');
	if (!key_value)
		return (1);
	if (get_array_height(key_value) > 2)
	{
		printf("msh: export: invalid args\n");
		free_char_array(key_value);
		return (1);
	}
	free_char_array(key_value);
	return (0);
}

/**
 * @brief determine whether a given string is a valid export call 
 * (with no equals in call)
 * 
 * 	@param 	str the subject string.
 *  @return 1: it is "
 *  @return 0: it is not "
*/
int	export_arg_neq_check(char *str)
{
	int	i;

	if (!ft_isalpha(str[0]))
	{
		return (0);
	}
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief determine whether a given string is a valid standard export= call
 *  * @param 	export_str the subject string.
 *
 *  return 1: it is "
 *  return 0: it is not "
*/
int	is_valid_eq_exp(char *export_str)
{
	int		i;

	i = 0;
	while (export_str[i] && export_str[i] != '=')
	{
		if (i == 0)
		{
			if (!(export_str[i] == '_' || ft_isalpha(export_str[i])))
				return (0);
		}
		if (!(ft_isalnum(export_str[i]) || export_str[i] == '_'))
			return (0);
		i++;
	}
	if (export_str[i] != '=')
	{
		printf("DEBUG! = not found\n");
		return (0);
	}
	return (1);
}

/**
 * @brief determine whether a given string is a valid export concat call
 *  * @param 	export_str the subject string.
 *
 *  return 1: it is "
 *  return 0: it is not "
*/
int	is_valid_concat_exp(char *export_str)
{
	int		i;

	i = 0;
	while (export_str[i] && export_str[i] != '+')
	{
		if (i == 0)
		{
			if (!(export_str[i] == '_' || ft_isalpha(export_str[i])))
				return (0);
		}
		if (!(ft_isalnum(export_str[i]) || export_str[i] == '_'))
			return (0);
		i++;
	}
	if (export_str[i] == '+' && export_str[i + 1] == '=')
		return (1);
	return (0);
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
int	msh_setenv(char *env_str, char ***envp)
{
	char	**envv;
	char	**new_envv;
	int		i;
	int		len;

	new_envv = NULL;
	envv = *envp;
	len = get_array_height(*envp);
	new_envv = malloc(sizeof(char *) * (len + 2));
	if (env_str == NULL || env_str[0] == '\0')
		return (1);
	if (ft_strrchr((const char *)env_str, '=') && msh_setenv1(env_str))
		return (1);
	i = -1;
	while (envv[++i])
		new_envv[i] = ft_strdup(envv[i]);
	new_envv[i] = ft_strdup(env_str);
	i++;
	new_envv[i] = NULL;
	free_char_array(*envp);
	*envp = new_envv;
	return (0);
}
