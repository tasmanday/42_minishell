/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:45:23 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 18:48:49 by tday             ###   ########.fr       */
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
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>

/*
** structs
*/

/* main struct */
typedef struct s_msh
{
	t_dlist	*envvar;
	char	*input;
	t_list	*tokens;
	t_dlist	*cmd_queue;
	int		num_of_cmds;
	t_list	*pids;
	int		last_exit_status;
	bool	print_paths;
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
	int		in_fd;
	int		out_fd;
	bool	is_append;
	char	*heredoc_delimiter;
	char	*heredoc_data;
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

void		expand_envvar(t_msh *msh, int *i);
char		*get_env_key(char *str);
char		*get_env_value(t_dlist *envvar, char *key);
t_dlist		*find_envvar_node(t_dlist *envvar, char *key);
void		update_node_value(t_dlist *envvar_node, char *new_value);

/* get_input */

char		*get_input(t_msh *msh);
bool		is_just_whitespace(char *input);

/* lexer */

void		add_tokens_to_list(t_msh *msh);
void		create_and_add_token(t_msh *msh, int start, int end);
t_list		*safe_new_token_node(t_msh *msh, char *str);
bool		is_valid_arg_char(char c);
void		check_redir(t_msh *msh, const char *input, int *i);
void		check_quotes(t_msh *msh, const char *input, int *i);
void		process_envvars(t_msh *msh);

/* parse */

void		extract_commands(t_msh *msh);
void		process_input(t_msh *msh);
void		process_fds(t_msh *msh);
void		process_pipe_fds(t_msh *msh);
void		handle_redirection(t_cmd *cmd, t_list **token_ptr);
bool		file_exists(const char *file_name);
bool		is_redirect(char *str);
int			get_open_flags(bool is_append);

/* signals.c */

void		handle_interrupt(int sig);
void		handle_quit(int sig);
void		setup_signal_handlers(void);
void		reset_signal_handlers(void);

/* builtins */

int			ft_pwd(t_msh *msh, t_cmd *cmd);
int			ft_echo(t_msh *msh, t_cmd *cmd);
int			ft_env(t_msh *msh, t_cmd *cmd);
int			ft_export(t_msh *msh, t_cmd *cmd);
int			ft_unset(t_msh *msh, t_cmd *cmd);
int			ft_cd(t_msh *msh, t_cmd *cmd);
int			ft_exit(t_msh *msh, t_cmd *cmd);
int			handle_too_many_args(void);

/* execute */

char		**put_args_in_array(t_cmd *cmd_struct);
char		**convert_envvar_to_array(t_msh *msh);
bool		cmd_is_builtin(char *command);
void		execute_builtin(t_msh *msh, t_dlist *curr_cmd);
void		execute_commands(t_msh *msh);
void		execute_parent(t_msh *msh, t_cmd *cmd_data);
void		execute_child(t_msh *msh, char **env, char **arg, t_cmd *cmd_data);
char		*get_path(t_msh *msh, char *command);
bool		has_path(char *string);
void		print_paths(t_msh *msh);

/* clean_up */

void		clean_exit(t_msh *msh, int exit_status);
void		msh_error_exit(t_msh *msh, char *error_message);
void		free_cloned_list(t_dlist *head);
void		free_everything(t_msh *msh);
void		free_envv_struct(void *data);
void		free_data(void *data);
void		free_tokens(t_msh *msh);
void		free_cmd_struct(void *data);
void		free_input(t_msh *msh);

#endif
