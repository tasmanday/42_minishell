/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:29:18 by tday              #+#    #+#             */
/*   Updated: 2024/01/26 13:49:50 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Summary
	reverses the order of the strings in the array.

	Inputs
	arr = an array of strings.
	size = the size of the array.

	Outputs
	none.
*/
void	reverse_str_arr(char **arr, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
		i++;
	}
}
