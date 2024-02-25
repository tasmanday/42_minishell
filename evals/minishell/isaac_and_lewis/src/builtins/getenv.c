/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:07:02 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 22:02:06 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief determine the number of characters prior to an '=' in an
 * environmental variable.
 *
 * @param key: the environmental value for comparison.
 * @return: the number of characters prior to '=' in an environmental variable.
*/
int	get_keylength(char *key)
{
	int	i;

	i = 0;
	while (key[i] && key[i] != '=')
	{
		i++;
	}
	if (!key[i])
	{
		print_err("DEBUG: get_keylength: Something is amiss!\n");
	}
	return (i);
}

/**
 * @brief creates a new string which contains len characters of str.
*/
char	*ft_strndup(const char *str, size_t len)
{
	char	*result;
	size_t	i;

	result = malloc(len + 1);
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] && i < len)
	{
		result[i] = str[i];
		i++;
	}
	while (i <= len)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}

/**
 * @brief  returns our envv name, similar to getenv but retrieving the 
 * envv 'key' instead of its value from envv.
 * *
 * @param char ***envp pointer to a valid environmental variable array.
 * @param char *envVar the envv we would like to extract our name/key from.
 * * @return  char *mKeys if succesful.
 * @return NULL if the given string is not found in envv.
*/
char	*envv_to_key(char **envv, const char *envVar, int is_concat)
{
	int		i;
	char	*name;
	char	**str_split;
	int		len;

	i = 0;
	str_split = ft_split(envVar, '=');
	if (!str_split)
		return (NULL);
	while (envv[i])
	{
		if (ft_strncmp(str_split[0], envv[i],
				ft_strlen(str_split[0]) - is_concat) == 0)
		{
			len = get_keylength((char *)envv[i]);
			name = ft_strndup(envv[i], len);
			if (!name)
				return (NULL);
			free_char_array(str_split);
			return (name);
		}
		i++;
	}
	free_char_array(str_split);
	return (NULL);
}

/**
 * @brief NORM_HELPER
*/
char	*msh_getenv_do(char **str_split, char **kv_split)
{
	char	*ret_str;

	ret_str = ft_strdup(kv_split[1]);
	free_char_array(kv_split);
	free_char_array(str_split);
	return (ret_str);
}

/**
 * @brief  returns our envv 'value', similar to getenv but accessing our own
 * envv array (which is dynamic/updated when we cd)
 * 
 * @param char *envv a valid environmental variable array.
 * @param char *str our comparison string.
 * @return  char *ret_str;
 * * @return NULL if the given string is not found in envv.
*/
char	*msh_getenv(char **envv, const char *str)
{
	int		i;
	char	**kv_split;
	char	**str_split;

	i = 0;
	str_split = ft_split(str, '=');
	if (!str_split)
		return (NULL);
	while (envv[i])
	{
		kv_split = ft_split(envv[i], '=');
		if (!kv_split)
			return (free_char_array(str_split), NULL);
		if (ft_strncmp(kv_split[0], str_split[0],
				ft_strlen(str_split[0]) + 1) == 0)
			return (msh_getenv_do(str_split, kv_split));
		else
			free_char_array(kv_split);
		i++;
	}
	free_char_array(str_split);
	return (NULL);
}
