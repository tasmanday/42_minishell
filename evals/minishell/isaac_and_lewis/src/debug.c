/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:58:17 by lxu               #+#    #+#             */
/*   Updated: 2023/09/13 17:07:16 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

/*
t_deque	clone_token_nodes(t_deque d)
{
	t_deque			clone;
	t_dlist			*node;
	t_token_node	*token;
	t_token_node	*new_token;

	clone = ft_deque_new();
	node = d.head;
	while (node)
	{
		token = node->content;
		new_token = clone_token_node(token);
		ft_deque_append(&clone, new_token);
		node = node->next;
	}
	return (clone);
}

void	debug_print_token_node_content2(t_token_node *token_node)
{
	printf("[OP  ]: ");
	if (token_node->content.op == DOUBLE_PIPE)
		printf("||");
	if (token_node->content.op == DOUBLE_AND)
		printf("&&");
	if (token_node->content.op == PIPE)
		printf("|");
	if (token_node->content.op == LEFT_BRACKET)
		printf("(");
	if (token_node->content.op == RIGHT_BRACKET)
		printf(")");
	if (token_node->content.op == DOUBLE_LESS_THAN)
		printf("<<");
	if (token_node->content.op == DOUBLE_GREATER_THAN)
		printf(">>");
	if (token_node->content.op == LESS_THAN)
		printf("<");
	if (token_node->content.op == GREATER_THAN)
		printf(">");
}

void	debug_print_token_node_content(t_token_node *token_node)
{
	if (token_node->type == WORD)
		printf("[WORD]: %s", token_node->content.str);
	if (token_node->type == REDIRECTION_WORD)
		printf("[R WO]: %s", token_node->content.str);
	if (token_node->type == REDIRECTION_DELIMITER)
		printf("[R DL]: %s", token_node->content.str);
	if (token_node->type == REDIRECTION_HEREDOC)
		printf("[R HD]: %d", token_node->content.fd);
	if (token_node->type == NONE_TYPE)
		printf("[NONE]: <debug: Token of type None. Error?");
	if (token_node->type == OPERATOR)
	{
		debug_print_token_node_content2(token_node);
	}
	printf("\n");
}

void	debug_print_token_node(t_token_node *t)
{
	printf("Token Node: ");
	if (!t)
	{
		printf("(null)\n");
	}
	else
	{
		debug_print_token_node_content(t);
	}
}

void	debug_print_tokens(t_deque tokens)
{
	t_dlist			*dlist_node;
	t_token_node	*token_node;
	int				i;

	i = 0;
	dlist_node = tokens.head;
	while (dlist_node)
	{
		token_node = dlist_node->content;
		printf("Token Node # %3i ", i);
		debug_print_token_node_content(token_node);
		dlist_node = dlist_node->next;
		i++;
	}
}

void	debug_print_linked_list_one_line(t_list *node)
{
	if (!node)
	{
		printf("(null)");
	}
	while (node)
	{
		printf("%s", (char *)node->content);
		if (node->next)
		{
			printf(" ");
		}
		node = node->next;
	}
}

void	debug_print_redirections_linked_list_one_line2(t_redirection	*r)
{
	if (r->type == REDIRECTION_IN)
		printf("in - ");
	else if (r->type == REDIRECTION_IN_HEREDOC)
		printf("heredoc - ");
	else if (r->type == REDIRECTION_OUT)
		printf("out - ");
	else if (r->type == REDIRECTION_OUT_APPEND)
		printf("append - ");
	else if (r->type == REDIRECTION_NONE)
		printf("(none) - ");
	else
		printf("(BUG?) - ");
}

void	debug_print_redirections_linked_list_one_line(t_list *node)
{
	t_redirection	*r;

	if (!node)
		printf("no redirections");
	while (node)
	{
		r = node->content;
		if (!r)
			printf("(null), ");
		if (r)
		{
			debug_print_redirections_linked_list_one_line2(r);
		}
		printf("%s, ", r->file_name);
		node = node->next;
	}
}

void	debug_print_command_oneline(t_ast_node *node, char **envv)
{
	t_command	*cmd;
	t_deque		tokens_clone;

	tokens_clone = clone_token_nodes(node->tokens);
	cmd = new_cmd_from_tokens(&tokens_clone, envv, 0);
	if (!cmd->args)
	{
		printf("CMD: <no args>\n");
		delete_command(cmd);
		return ;
	}
	printf("CMD: %s  in: %i  out: %i  args: ",
		(char *)cmd->args->content, node->fd_in, node->fd_out);
	debug_print_linked_list_one_line(cmd->args);
	printf(" redirections: ");
	debug_print_redirections_linked_list_one_line(cmd->redirections);
	printf("\n");
	delete_command(cmd);
}

void	debug_pretty_print_command(t_ast_node *node, char *pre, char **envv)
{
	char		*new_pre;
	t_command	*cmd;
	t_deque		tokens_clone;

	tokens_clone = clone_token_nodes(node->tokens);
	cmd = new_cmd_from_tokens(&tokens_clone, envv, 0);
	if (!cmd->args)
	{
		printf("[CMD ] <no args>\n");
		delete_command(cmd);
		return;
	}
	printf("[CMD ] cmd: %s\n", (char *)cmd->args->content);
	new_pre = ft_strconcat(2, pre, "      ");
	if (cmd->args)
	{
		printf("%s args: ", new_pre);
		debug_print_linked_list_one_line(cmd->args);
		printf("\n");
	}
	if (node->fd_in != 0 || node->fd_out != 1)
	{
		printf("%s pipe in: %i    pipe out: %i\n", new_pre, node->fd_in,
			node->fd_out);
	}
	if (cmd->redirections)
	{
		printf("%s redirections: ", new_pre);
		debug_print_redirections_linked_list_one_line(cmd->redirections);
		printf("\n");
	}
	free(new_pre);
	delete_command(cmd);
}

void	debug_pretty_print_brackets(t_ast_node *node, char *pre)
{
	char	*new_pre;
	t_deque	tokens_clone;
	t_list	*redirections;

	tokens_clone = clone_token_nodes(node->tokens);
	redirections = tokens_to_redirection_list(&tokens_clone);

	printf("[ () ] - Brackets\n");
	if (redirections)
	{
		new_pre = ft_strconcat(2, pre, " |      ");
		printf("%s redirections: ", new_pre);
		debug_print_redirections_linked_list_one_line(redirections);
		printf("\n");
		free(new_pre);
	}
	ft_lstclear(&redirections, delete_redirection_void);
}

void	debug_print_ast_node_content(t_ast_node *node, char *pre, char **envv)
{
	if (!node)
	{
		printf("[null] - null node\n");
		return ;
	}
	if (node->type == AST_NONE)
	{
		printf("[NONE] - None containing AST node\n");
	}
	if (node->type == AST_CMD)
	{
		debug_pretty_print_command(node, pre, envv);
	}
	if (node->type == AST_PIPE)
	{
		printf("[ |  ] - Pipe\n");
	}
	if (node->type == AST_AND)
	{
		printf("[ && ] - And\n");
	}
	if (node->type == AST_OR)
	{
		printf("[ || ] - Or\n");
	}
	if (node->type == AST_BRACKETS)
	{
		// printf("[ () ] - Brackets\n");
		debug_pretty_print_brackets(node, pre);
	}
}

void	debug_print_ast_node(t_ast_node *node, char *pre, char **envv,
		int is_last)
{
	char	*new_pre;

	if (is_last)
	{
		printf("%s └─", pre);
		new_pre = ft_strconcat(2, pre, "   ");
		debug_print_ast_node_content(node, new_pre, envv);
		if (node != NULL && node->type != AST_CMD)
		{
			debug_print_ast_node(node->left, new_pre, envv, FALSE);
			debug_print_ast_node(node->right, new_pre, envv, TRUE);
		}
		free(new_pre);
	}
	else
	{
		printf("%s ├─", pre);
		new_pre = ft_strconcat(2, pre, " | ");
		debug_print_ast_node_content(node, new_pre, envv);
		if (node != NULL && node->type != AST_CMD)
		{
			debug_print_ast_node(node->left, new_pre, envv, FALSE);
			debug_print_ast_node(node->right, new_pre, envv, TRUE);
		}
		free(new_pre);
	}
}

void	debug_print_ast_tree(t_ast_node *head, char **envv)
{
	debug_print_ast_node(head, "", envv, TRUE);
}

char **generate_block(t_ast_node *node, size_t *cmd_number,
		t_deque *command_and_bracket_nodes)
{
	if (!node)
	{
		return (NULL);
	}
	if (!node->left && !node->right)
	{
		char **result = malloc(sizeof(char *) * 2);
		result[1] = NULL;
		if (node->type == AST_NONE)
		{
			result[0] = ft_strdup("(none)");
		}
		if (node->type == AST_PIPE)
		{
			result[0] = ft_strdup("|");
		}
		if (node->type == AST_AND)
		{
			result[0] = ft_strdup("&&");
		}
		if (node->type == AST_OR)
		{
			result[0] = ft_strdup("||");
		}
		if (node->type == AST_CMD)
		{
			result[0] = ft_itoa(*cmd_number);
			// handle numbers that are too wide?
			(*cmd_number)++;
			ft_deque_append(command_and_bracket_nodes, node);
			// result[0] = ft_strdup("cmd");
		}
		if (node->type == AST_BRACKETS)
		{
			char *tmp = ft_itoa(*cmd_number);
			(*cmd_number)++;
			result[0] = ft_strjoin("()", tmp);
			free(tmp);
			ft_deque_append(command_and_bracket_nodes, node);
			// result[0] = ft_strdup("()");
		}
		return result;
	}

	char **left = generate_block(node->left, cmd_number,
			command_and_bracket_nodes);
	char **right = generate_block(node->right, cmd_number, 
			command_and_bracket_nodes);
	size_t left_width = 1;
	size_t left_height = 0;
	size_t left_top = 0;

	if (left && left[0])
	{
		left_width = ft_strlen(left[0]);
		while (left[left_height] != NULL)
		{
			left_height++;
		}
		while (left[0][left_top] == ' ')
		{
			left_top++;
		}
	}
	size_t right_width = 1;
	size_t right_height = 0;
	size_t right_top = 0;
	if (right && right[0])
	{
		right_width = ft_strlen(right[0]);
		while (right[right_height] != NULL)
		{
			right_height++;
		}
		while (right[0][right_top] == ' ')
		{
			right_top++;
		}
	}

	size_t final_height = left_height + 2; // 1 for node, 1 for +---+--+
	if (right_height > left_height)
	{
		final_height = right_height + 2;
	}
	char **combined_block = malloc(sizeof(char *) * (final_height + 1)); 

	size_t combined_block_width = left_width + 3 + right_width;
	if (combined_block_width < left_width + 8)
	{
		combined_block_width = left_width + 7;
	}

	// put in top node
	combined_block[0] = malloc(sizeof(char) * (combined_block_width + 1));
	ft_memset(combined_block[0], ' ', combined_block_width);
	combined_block[0][combined_block_width] = '\0';
	// ft_memset(combined_block[0], ' ', left_width);
	if (node->type == AST_NONE)
	{
		ft_memcpy(combined_block[0] + left_width, " (none)", 7);
	}
	if (node->type == AST_PIPE)
	{
		ft_memcpy(combined_block[0] + left_width, " |", 2);
	}
	if (node->type == AST_AND)
	{
		ft_memcpy(combined_block[0] + left_width, " &&", 3);
	}
	if (node->type == AST_OR)
	{
		ft_memcpy(combined_block[0] + left_width, " ||", 3);
	}
	if (node->type == AST_CMD)
	{
		char *cmd_number_str = ft_itoa(*cmd_number);
		// handle number that are too wide?
		(*cmd_number)++;
		// ft_memcpy(combined_block[0] + left_width, cmd_number_str, 7);
		ft_strlcpy(combined_block[0] + left_width, cmd_number_str, 7);
		free(cmd_number_str);
		ft_deque_append(command_and_bracket_nodes, node);
		// ft_memcpy(combined_block[0] + left_width, " cmd", 4);
	}
	if (node->type == AST_BRACKETS)
	{
		char *tmp = ft_itoa(*cmd_number);
		(*cmd_number)++;
		char *tmp2 = ft_strjoin(" ()", tmp);
		free(tmp);
		ft_memcpy(combined_block[0] + left_width, tmp2, 4);
		free(tmp2);
		ft_deque_append(command_and_bracket_nodes, node);
		// ft_memcpy(combined_block[0] + left_width, " ()", 3);
	}

	// put in +---+----+
	combined_block[1] = malloc(sizeof(char) * (combined_block_width + 1));
	ft_memset(combined_block[1], ' ', combined_block_width);
	combined_block[1][combined_block_width] = '\0';

	// ft_memset(combined_block[1], ' ', left_top);
	combined_block[1][left_top] = '+';
	ft_memset(combined_block[1] + left_top + 1, '-', left_width - left_top);
	ft_memcpy(combined_block[1] + left_width, "-+-", 3);
	ft_memset(combined_block[1] + left_width + 3, '-', right_top);
	combined_block[1][left_width + 3 + right_top] = '+';

	size_t i = 2;
	size_t left_i = 0;
	size_t right_i = 0;
	while (i < final_height)
	{
		combined_block[i] = malloc(sizeof(char) * combined_block_width + 1);
		ft_memset(combined_block[i], ' ', combined_block_width);
		combined_block[i][combined_block_width] = '\0';
		if (left_i < left_height)
		{
			ft_memcpy(combined_block[i], left[left_i], ft_strlen(left[left_i]));
			left_i++;
		}
		if (right_i < right_height)
		{
			ft_memcpy(combined_block[i] + left_width + 3, right[right_i],
					ft_strlen(right[right_i]));
			right_i++;
		}
		i++;
	}
	combined_block[i] = NULL;

	if (left)
	{
		free_char_array(left);
	}
	if (right)
	{
		free_char_array(right);
	}

	return (combined_block);
}

void	debug_pretty_print_ast_tree(t_ast_node *head, char **envv)
{
	size_t	cmd_number = 1;
	t_deque	command_and_bracket_nodes = ft_deque_new();
	char **final_block = generate_block(head, &cmd_number,
			&command_and_bracket_nodes);

	size_t i = 0;
	while (final_block && final_block[i])
	{
		printf("%s\n", final_block[i]);
		i++;
	}

	if (command_and_bracket_nodes.head != NULL)
	{
		printf("\n");
	}
	t_ast_node *node;
	i = 1;
	while (1)
	{
		node = ft_deque_popleft(&command_and_bracket_nodes);
		if (!node)
		{
			break ;
		}
		printf("%zu :", i);
		debug_print_ast_node_content(node, "", envv);
		i++;
	}

	if (final_block)
	{
		free_char_array(final_block);
	}
}
*/
