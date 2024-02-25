/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:32:27 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 21:40:08 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * @brief	create a new string from an old string,
 *  		in which all of our characters are lowercase.
 * 
 * @param 	char *str the contents of our old string
 * @return 	our lowercase string
 * @return 	NULL if errors occur.
*/
char	*get_lowercase_str(char *str)
{
	int		i;
	char	*new_string;

	i = 0;
	new_string = malloc (sizeof(char) * (ft_strlen(str) + 1));
	if (!new_string)
	{
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			new_string[i] = str[i] + 32;
		}
		else
		{
			new_string[i] = str[i];
		}
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/**
 * @brief	Determine whether or not a given string is one of our 
 * 			builtin commands. 
 *
 * @param 	char *env_str the contents of our new environmental variable.
 * @return 	1 if it is a builtin string.
 * @return 	0 if it is not a builtin string.
*/
int	is_builtin_cmd(char *str)
{
	char	*builtin_cmds[8];
	char	*l_str;
	int		i;

	builtin_cmds[0] = "echo";
	builtin_cmds[1] = "cd";
	builtin_cmds[2] = "pwd";
	builtin_cmds[3] = "export";
	builtin_cmds[4] = "unset";
	builtin_cmds[5] = "env";
	builtin_cmds[6] = "exit";
	builtin_cmds[7] = NULL;
	l_str = get_lowercase_str(str);
	i = 0;
	while (builtin_cmds[i])
	{
		if (ft_strncmp(l_str, builtin_cmds[i], ft_strlen(l_str)) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief  	frees whatever we have already malloced in our new env array
 * 			used in the case of failure to ft_strdup/malloc new memory.
 *
 * @param 	char **arr our array that requires freeing til n.
 * @param 	int	n the number of elements we need to free in our array
*/
void	free_ar_til(char **arr, int n)
{
	int	i;

	i = 0;
	while (arr[i] && i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
 * @brief  	swap the values of the strings at the given address'
 *
 * @param  str1 : the address of the first string to be swapped.
 * @param  str2 : the address of the second string to be swapped.
 * */
void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	if (!str1 || !str2)
		return ;
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

/**
 * @brief retrieve the height of a given array of strings.
 *
 * @param str_array the string array to be evaluated.
 * @return the height of the array. 
*/
int	get_array_height(char **str_array)
{
	int	count;

	count = 0;
	while (str_array[count])
	{
		count++;
	}
	return (count);
}
