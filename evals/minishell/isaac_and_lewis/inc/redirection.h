/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:30:24 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:36:25 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "parse.h"
# include <fcntl.h>
# include <readline/readline.h>
# include "tilde_expansion.h"
# include "parameter_expansion.h"
# include "filename_expansion.h"
# include "split.h"
# include "quote_removal.h"
# include "utils.h"
# include <sys/wait.h>
# include <errno.h>

enum e_redirection_type {
	REDIRECTION_NONE,
	REDIRECTION_IN,
	REDIRECTION_IN_HEREDOC,
	REDIRECTION_OUT,
	REDIRECTION_OUT_APPEND,
};

typedef struct s_redirection {
	enum e_redirection_type	type;
	char					*file_name;
	int						old_fd;
	int						new_fd;
}	t_redirection;

typedef struct s_ast_node	t_ast_node;

t_list			*tokens_to_redirection_list(t_deque *t);
int				handle_redirections(t_list *r, char **envv, int last_exit);

/*				redirection1.c*/
t_redirection	*new_redirection(void);
int				delete_redirection(t_redirection *r);
void			delete_redirection_void(void *void_ptr);
t_redirection	*new_redirection_with_type_from_op(enum e_operator op);
void			print_open_error(char *file_name);

/*				redirection2.c*/
int				preprocess_redirection_word(char **word, char **envv,
					int last_exit);

/*				redirection3.c*/
int				preprocess_redirection_words(t_list *redirections,
					char **envv, int last_exit);
void			dup_fd(t_redirection *r);
void			dup_fds(t_list *redirections);
int				handle_redirections(t_list *redirections, char **envv,
					int last_exit);

/*				redirection4.c*/
int				open_fd(t_redirection *r);
int				open_fds(t_list	*redirections);

#endif
