/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:45:23 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 14:51:32 by tday             ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h> 

/*
** structs
*/

/* main struct */
typedef struct s_msh
{
	t_dlist	*envvar;
	t_list	*tokens;
	t_dlist	*cmd_queue;
	int		num_of_cmds;
	t_list	*pids;
	int		last_exit_status;
}				t_msh;

/* elements in envvar*/
typedef struct s_envv
{
	char	*env_key;
	char	*env_value;
}				t_envv;

/* elements in cmd_list */
typedef struct s_cmd
{
	char	*command;
	t_list	*arguments;
	char	*input_file;
	char	*output_file;
	int	in_fd;
	int	out_fd;
	bool	is_append;
}				t_cmd;

/*
** prototypes
*/

/* initialisation */

t_msh		*init_minishell(char **envv);
void		clone_envv_to_dlist(t_msh *msh, char **envv);
char		**split_variables(char *envv);
t_envv		*put_str_in_envv_struct(char **cloned_substrs);
void		add_envv_to_dlist(t_msh *msh, t_envv *s_envv);

/* envv */

void		expand_envvar(t_dlist *envvar, char **str, int *i);
char		*get_env_key(char *str);
char		*get_env_value(t_dlist *envvar, char *key);
t_dlist		*find_envvar_node(t_dlist *envvar, char *key);
void		update_node_value(t_dlist *envvar_node, char *new_value);

/* get_input */

char		*get_input(t_msh *msh, char *prompt);

/* lexer */

void		add_tokens_to_list(t_msh *msh, char *str);
void		handle_meta_chars(t_msh *msh, char *str, int *i);
t_list		*safe_new_token_node(t_msh *msh, char *str);

/* parse */

void		extract_commands(t_msh *msh);
void		process_input(t_msh *msh, char *input);
void		process_fds(t_msh *msh);

/* builtins */

void		ft_pwd(t_msh *msh);
void		ft_echo(t_dlist *curr_cmd);
void		ft_env(t_msh *msh);
void		ft_export(t_msh *msh);
void		ft_unset(t_msh *msh);
void		ft_cd(t_msh *msh);
void		ft_exit(t_msh *msh);

/* execute */

char		**put_args_in_array(t_cmd *cmd_struct);
char		**convert_envvar_to_array(t_msh *msh);
bool		cmd_is_builtin(char *command);
void		execute_builtin(t_msh *msh, t_dlist *curr_cmd);
void		execute_commands(t_msh *msh);
void		execute_parent(t_msh *msh, t_cmd *cmd_data);
void		execute_child(t_msh *msh, char **env, char **arg);
char		*get_path(t_msh *msh, char *command);
bool		has_path(char *string);

/* clean_up */

void		clean_exit(t_msh *msh, int exit_status);
void		msh_error_exit(t_msh *msh, char *error_message);
void		free_cloned_list(t_dlist *head);
void		free_everything(t_msh *msh);
void		free_envv_struct(void *data);
void		free_data(void *data);
void		free_tokens(t_msh *msh);
void		free_cmd_struct(void *data);
void		free_input(t_msh *msh, char *input);

#endif
