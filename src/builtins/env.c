/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:24:21 by tday              #+#    #+#             */
/*   Updated: 2024/02/07 23:24:21 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	print_envv(t_envv *envv_element) {
    if (envv_element != NULL) {
        ft_printf("%s\n", envv_element->env_variable);
    }
}

int	ft_env(t_dlist *env_dlist)
{
	t_dlist	*current;

	current = env_dlist;
	while (current)
	{
		print_envv((t_envv *)current->data);
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

/* write function for freeing allocated memory from clone_envv_to_dlist 

	gpt function:
	
	void free_dlist(t_dlist *list) {
    t_dlist *current = list;
    t_dlist *next;

    while (current != NULL) {
        next = current->next; // Save reference to next node
        t_envv *envv = (t_envv *)current->data; // Cast the data back to t_envv*

        if (envv != NULL) {
            free(envv->env_variable); // Free the string
            free(envv); // Free the t_envv structure
        }

        free(current); // Free the list node itself
        current = next; // Move to next node
    }
}

*/