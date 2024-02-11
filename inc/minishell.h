/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:45:23 by tday              #+#    #+#             */
/*   Updated: 2024/02/11 19:51:01 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** includes
*/

# include "../libft/inc/libft.h"

/*
** structs
*/

typedef struct s_envv
{
	char	*env_key;
	char	*env_value;
}				t_envv;


/*
** prototypes
*/

/* initialisation */

void		clone_envv_to_dlist(char **envv, t_dlist **env_list);

/* builtins */

int			ft_pwd(void);
int			ft_echo(char **argv);
int			ft_env(t_dlist *env_dlist);

/* clean_up */
void		free_envv_struct(void *data);

#endif