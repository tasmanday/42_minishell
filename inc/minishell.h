/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:45:23 by tday              #+#    #+#             */
/*   Updated: 2024/03/01 16:36:41 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** includes
*/

# include "../libft/inc/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

/*
** structs
*/

typedef struct s_msh
{
	t_dlist		*envvar;
	t_list		*tokens;
//	t_termcaps	*termcaps;
}				t_msh;


typedef struct s_envv
{
	char	*env_key;
	char	*env_value;
}				t_envv;

/* typedef struct s_termcaps
{
	struct termios	original_term;
	struct termios	new_term;
	char			*buffer;
}				t_termcaps; */


/*
** prototypes
*/

/* initialisation */

void		init_minishell(t_msh *msh, char **argv, char **envv);
void		clone_envv_to_dlist(char **envv, t_dlist **envvar);
void		get_tokens_from_input(t_msh *msh, char **argv);

/* get_input */

char		*get_input(t_msh *msh, char *prompt);

/* envv */

void		expand_envvar(t_dlist *envvar, char **str, int *i);
char		*get_env_key(char *str);
char		*get_env_value(t_dlist *envvar, char *key);
t_dlist		*find_envvar_node(t_dlist *envvar, char *key);

/* builtins */

void		ft_pwd(t_msh *msh);
void		ft_echo(t_msh *msh);
void		ft_env(t_msh *msh);

/* parse */

void		add_tokens_to_list(t_msh *msh, char *str);
void		handle_meta_chars(t_msh *msh, char *str, int *i);
t_list		*safe_new_token_node(t_msh *msh, char *str);

/* clean_up */

void		clean_exit(t_msh *msh, int exit_status);
void		free_envv_struct(void *data);
void		free_string(void *data);
void		free_everything(t_msh *msh);

#endif