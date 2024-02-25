/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:42:35 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 21:37:57 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * @brief copy a string array into a newly allocated array.
 *
 * @param str_array the string array to be copied.
 * @param count the number of elements we wish to copy into 
 * our new array.
 * @return NULL if allocation has failed.
 * @return the new array if allocation has succeeded.
*/
char	**copy_str_array(char **str_array, int count)
{
	int		i;
	char	**new_array;

	new_array = malloc(sizeof(char *) * (count + 1));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_array[i] = ft_strdup(str_array[i]);
		if (!new_array[i])
		{
			free_ar_til(new_array, i);
			return (NULL);
		}
		i++;
	}
	new_array[count] = NULL;
	return (new_array);
}

/**
 * @brief sort a given string array alphabetically.
 *
 * @param str_array the string array to be copied into our alpha array.
 * @return NULL if allocation has failed.
 * @return the new array if allocation has succeeded.
*/
char	**get_alpha_order(char **str_array)
{
	int		count;
	int		i;
	int		j;
	char	**new_arr;

	count = get_array_height(str_array);
	new_arr = copy_str_array(str_array, count);
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strncmp(new_arr[i], new_arr[j], ft_strlen(new_arr[i])) > 0)
				ft_swap(&new_arr[i], &new_arr[j]);
			j++;
		}
		i++;
	}
	return (new_arr);
}

void	print_export_env_do(int j, char **alpha_envv)
{
	int	k;

	write(1, "declare -x ", 11);
	k = 0;
	while (alpha_envv[j][k] && alpha_envv[j][k] != '=')
	{
		write(1, &alpha_envv[j][k], 1);
		k++;
	}
	if (alpha_envv[j][k])
	{
		write(1, "=\"", 2);
		k++;
		while (alpha_envv[j][k])
		{
			write(1, &alpha_envv[j][k], 1);
			k++;
		}
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
	free (alpha_envv[j]);
}

/**
 * @brief Prints env with declare -x before each line.
 *
 * @param char **args The arguments of our call 
 * @param char **envv a valid environmental variable array.
*/
int	print_export_env(char **args, char **envv)
{
	int		i;
	int		j;
	char	**alpha_envv;

	i = 0;
	alpha_envv = get_alpha_order(envv);
	if (!alpha_envv)
		return (1);
	while (args[i])
		i++;
	if (i <= 1)
	{
		j = 0;
		while (alpha_envv[j])
		{
			print_export_env_do(j, alpha_envv);
			j++;
		}
		free(alpha_envv);
	}
	return (0);
}

/*
 * brief: form a call for builtin unset.
 */
int	unset_caller(char *env_name, char ***envp)
{
	char	**unset_call;

	unset_call = malloc(sizeof(char *) * 3);
	if (!unset_call)
	{
		return (1);
	}
	unset_call[0] = ft_strdup("unset");
	unset_call[1] = ft_strdup(env_name);
	unset_call[2] = NULL;
	builtin_unset(unset_call, envp);
	free_char_array(unset_call);
	return (0);
}
