/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:35:18 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/11 20:09:54 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * @brief	determine whether a given string is a valid flag string
 *
 * @param 	str: the query string.
 * @return 	1 if the string is a valid flag
 * @return 	0 if not.
*/
int	is_not_exception_case(char *str)
{
	if (ft_strlen(str) < 18)
		return (0);
	else if (ft_strncmp(str, "-9223372036854775808", ft_strlen(str)) == 0)
		return (0);
	else if (ft_strncmp(str, "9223372036854775807", ft_strlen(str)) == 0)
		return (0);
	else if (ft_strncmp(str, "0000000000000000000000", ft_strlen(str)) == 0)
		return (0);
	else if (ft_strncmp(str, "0000000000000000000001", ft_strlen(str)) == 0)
		return (0);
	return (1);
}

/**
 * @brief determine whether a string contains all numeric characters or not.
 *
 * @param char *str the string in question.
*/
int	arg_is_validint(char *str)
{
	int	i;
	int	has_writ;

	i = 0;
	has_writ = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!(str[i] == '-' || str[i] == '+' || ft_isdigit(str[i])))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		has_writ = 1;
		i++;
	}
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i])
		return (0);
	if (has_writ)
		return (1);
	return (0);
}

/**
 * @brief call exit with the appropriate exit code, 
 * printing to STDERR as required.
 *
 * @param char **args the string in question.
*/
void	exit_caller(char **args)
{
	int	exit_code;

	if (!args[1])
	{
		exit_code = 0;
	}
	else if (is_not_exception_case(args[1]))
	{
		print_err("msh: exit: %s: numeric argument required\n", args[1]);
		exit_code = 255;
	}
	else if (arg_is_validint(args[1]))
	{
		exit_code = ft_atoi(args[1]);
	}
	else
	{
		print_err("msh: exit: %s: numeric argument required\n", args[1]);
		exit_code = 255;
	}
	free_char_array(args);
	exit(exit_code);
}

/**
 * @brief  exit - cause normal process termination
 *
 * @param char **args The arguments of our call 
 * @param char ***envp ptr to a valid environmental variable array.
 * @return 0/EXIT_SUCCESS on successful execution
 * @return 1/EXIT_FAILURE if an error occurs.
*/
int	builtin_exit(char **args, char ***envp)
{
	(void)envp;
	if (args[1] && !arg_is_validint(args[1]))
	{
		print_err("msh: exit: %s: numeric argument required\n", args[1]);
		exit(255);
	}
	else if (get_array_height(args) > 2)
	{
		write(2, "msh: exit: too many arguments\n", 30);
		return (1);
	}
	exit_caller(args);
	return (0);
}
