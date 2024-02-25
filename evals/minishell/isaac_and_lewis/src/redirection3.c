/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:18:51 by ivanderw          #+#    #+#             */
/*   Updated: 2023/09/13 12:36:35 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

/**
 * @brief Applies redirection word preprocessing to redirections
 * 
 * Applies redirection word preprocessing to all redirections except heredocs
 * (these would have already been handled earlier when the heredoc was created)
 * 
 * @param redirections The list of redirections to preprocess
 * @param envv The envv (for expansions)
 * @param last_exit The last exit (for expansions)
 * @return int Error return. 1 if error. 0 if no error.
 */
int	preprocess_redirection_words(t_list *redirections, char **envv,
		int last_exit)
{
	t_redirection	*r;
	int				error_return;

	while (redirections)
	{
		r = redirections->content;
		if (!(r->type == REDIRECTION_IN_HEREDOC))
		{
			error_return = preprocess_redirection_word(&r->file_name,
					envv, last_exit);
			if (error_return != 0)
			{
				return (error_return);
			}
		}
		redirections = redirections->next;
	}
	return (0);
}

/**
 * @brief Dup the redirections into place.
 * 
 * Dup the open FDs into the correct place.
 * 
 * @param r The redirection to be dup'd.
 */
void	dup_fd(t_redirection *r)
{
	if (!r)
	{
		return ;
	}
	if (r->old_fd < 0 || r->new_fd < 0)
	{
		return ;
	}
	dup2(r->new_fd, r->old_fd);
}

/**
 * @brief Dup in the redirections specified by a list of redirection objects
 * 
 * Dup the open FDs into the correct place. Done sequentially, will override
 * repeated dup2s as expected.
 * 
 * @param redirections The list of redirections to be dup'd.
 */
void	dup_fds(t_list *redirections)
{
	t_redirection	*r;

	while (redirections)
	{
		r = redirections->content;
		if (!r)
		{
			break ;
		}
		dup_fd(r);
		redirections = redirections->next;
	}
}

/**
 * @brief Executes the redirections.
 * 
 * Takes a list of redirections and "executes" them.
 * 
 * Opens files as necessary.
 * 
 * Then dups the fds as appropriate. Will override the dup if there is multiple
 * (this is expected behaviour). Eg:
 * 
 * > out.txt > out2.txt
 * 
 * Will only write to out2.txt. out1.txt will be created but be empty.
 * 
 * @param redirections 
 * @param envv 
 * @param last_exit 
 * @return int 
 */
int	handle_redirections(t_list *redirections, char **envv, int last_exit)
{
	int	error_return;

	error_return = preprocess_redirection_words(redirections, envv, last_exit);
	if (error_return != 0)
	{
		return (error_return);
	}
	error_return = open_fds(redirections);
	if (error_return != 0)
	{
		return (error_return);
	}
	dup_fds(redirections);
	return (0);
}

/**
 * @brief Processes redirection word according to bash rules
 * 
 * Redirection words/delimiters are expanded by parameter expansion, filename
 * expansion, word splitting and quote removal.
 * 
 * However, in a number of scenarios this results in an "ambiguous redirect"
 * which results in an error return.
 * 
 * Ambiguous redirects include:
 *   - parameter expansion that results in a null string.
 *   - parameter expansion that results in a word that would be word split into
 *     more than one word.
 *   - filename expansion into multiple words.
 * 
 * @param word The word/delimiter to be processed.
 * @param envv The current envv (for expansion).
 * @param last_exit The last_exit value (for expansion)
 * @return int Return value. 1 if error. 0 if no error.
 */
int	preprocess_redirection_word(char **word, char **envv, int last_exit)
{
	char	*tilde_expanded_str;
	char	*parameter_expanded_str;
	t_deque	split_result;

	if (!word)
		return (1);
	tilde_expanded_str = tilde_expand_string(*word, envv);
	parameter_expanded_str = make_expanded_string(*word, envv, last_exit);
	free(tilde_expanded_str);
	if (ft_strncmp(parameter_expanded_str, "", 1) == 0)
		return (free(parameter_expanded_str), 1);
	split_result = split_word(parameter_expanded_str);
	if (ft_deque_length(split_result) > 1)
		return (free(parameter_expanded_str),
			ft_deque_destroy_list(&split_result, free), 1);
	ft_deque_destroy_list(&split_result, free);
	split_result = filename_expand_word(parameter_expanded_str);
	if (ft_deque_length(split_result) > 1)
		return (free(parameter_expanded_str),
			ft_deque_destroy_list(&split_result, free), 1);
	ft_deque_destroy_list(&split_result, free);
	remove_quotes_string(parameter_expanded_str);
	free(*word);
	*word = parameter_expanded_str;
	return (0);
}
