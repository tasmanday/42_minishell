/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:57:47 by lxu               #+#    #+#             */
/*   Updated: 2022/06/09 00:34:52 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstindex(t_list *lst, size_t index)
{
	size_t	i;

	if (!lst)
	{
		return (NULL);
	}
	i = 0;
	while (lst)
	{
		if (i == index)
		{
			return (lst);
		}
		lst = lst->next;
		i++;
	}
	return (NULL);
}
