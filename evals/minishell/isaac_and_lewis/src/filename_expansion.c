/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:43:50 by lxu               #+#    #+#             */
/*   Updated: 2023/09/12 19:04:46 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filename_expansion.h"
/*
 * words with * are replaced with an alphabetically sorted list of filenames 
 * matching the pattern
 * the character '.' at the start or following / must be matched explicitly. 
 * Eg ~/ * doesnt match ~/. or ~/.. (~/.* will match both though)
 * a slash must always be matched explicitly. eg ~/
 * world won't match 
 * ~/foo/bar/world but could match ~/foo/world
 * if no match is found, word is left unchanged (eg hello*world will remain 
 * if no matches are found for hello<something>world)
 * to check. does ~ match? eg ~/Desktop/etc...
 * to check. what if asterisk in parameter expansion
 * consider whether i want to support globstar (and if globstar is default. 
 * ie behaviour of ~/Desktop
*/
/**
 * @brief Returns a deque with a list of filenames that match the pattern.
 *
 * Searches the current directory for all filenames that satisfy the glob rules
 * of the provided pattern.
 *
 * Follows the bash rules for the pattern matching.
 *     '*' char matches zero or more of any character
 *     files starting with a '.' char must be explicitly matched (ie cant be
 *         matched by a leading glob *)
 *
 * Limited by our provided project specification. Only matches on the current
 * directory. Ie will not match * within a path (eg: p*th/to/som*thing/test.txt)
 * or in absolute paths (eg: /home/test/foo*.txt).
 *
 * Return deque will be zero length if no matching filenames are found.
 *
 * @param The pattern to be matched against.
 * @return A deque of all matching filenames.
 */
t_deque	get_list_of_filenames_matching_pattern(char *pattern)
{
	DIR				*dir_ptr;
	struct dirent	*dir_entry;
	t_deque			result;

	result = ft_deque_new();
	if (!pattern)
		return (result);
	dir_ptr = opendir(".");
	if (!dir_ptr)
		return (result);
	while (1)
	{
		dir_entry = readdir(dir_ptr);
		if (dir_entry == NULL)
			break ;
		if (str_matches_pattern(dir_entry->d_name, pattern) == 1)
		{
			if (dir_entry->d_name[0] != '.' || pattern[0] == '.')
				ft_deque_append(&result, ft_strdup(dir_entry->d_name));
		}
	}
	closedir(dir_ptr);
	return (result);
}

/**
 * @brief Expands word with valid filename globbing.
 *
 * Returns the result of the expansion of the glob star following bash rules.
 *
 * Shortcuts if there is no star in the word. Warns (and ignores the glob stars)
 * if there are any path separator chars ('/') in the word suggesting that the
 * user is trying to expand out a full path (or absolute path) both of which
 * are unsupported.
 *
 * Handles the scenario where there are no matching files. In this sitation, per
 * bash, the word is kept and passed on (with the asterisk(s) included).
 *
 * Also of note. Not mentioned in the bash man about redirection but infered
 * through testing.
 *     * char is ignored if it is inside quotes
 *     chars thenselves that are quoted are matched as if they are not quoted
 *     eg *".txt" matches the same as *.txt
 *     but, "*.txt" matches to the explicit string "*.txt" with glob ignored.
 *
 * If the expansion is successful, per bash, it is alphabetised before being
 * returned.
 *
 * @param str The pattern string to look for in the current directory.
 * @return A deque with all matching filenames in alphabetical order, or,
 *     the original pattern string if no matching filenames are found.
 */
t_deque	filename_expand_word(char *str)
{
	t_deque	result;

	result = ft_deque_new();
	if (!str)
		return (result);
	if (ft_isinstr('*', str) == 0)
	{
		ft_deque_append(&result, ft_strdup(str));
		return (result);
	}
	if (ft_isinstr('/', str) == 1)
	{
		print_err("msh_warn: filename_expand_word\n");
		ft_deque_append(&result, ft_strdup(str));
		return (result);
	}
	result = get_list_of_filenames_matching_pattern(str);
	if (ft_deque_length(result) == 0)
	{
		ft_deque_append(&result, ft_strdup(str));
		return (result);
	}
	deque_bubble_sort(result, compare_strings_helper);
	return (result);
}

/**
 * @brief Apply filename expansion to the string content in a token_node.
 *
 * Takes a token node and applies filename expansion to it's content string.
 * Returns a deque of the resulting token_nodes.
 *
 * Returns just the original node if the node was an operator type.
 *
 * @param token_node The token node to perform expansion on.
 * @return A deque containing the node(s) after filename expansion has occurred.
 */
t_deque	filename_expand_token(t_token_node *token_node)
{
	t_deque	filename_expansions;
	t_dlist	*filename_node;
	t_deque	res;

	res = ft_deque_new();
	if (!token_node)
		return (res);
	if (token_node->type == OPERATOR)
		return (ft_deque_append(&res,
				new_operator_token_node(token_node->content.op)), res);
	if (ft_isinstr('*', token_node->content.str) == 0)
		return (ft_deque_append(&res,
				new_str_t_n(token_node->type, token_node->content.str)), res);
	filename_expansions = filename_expand_word(token_node->content.str);
	filename_node = filename_expansions.head;
	while (filename_node)
	{
		ft_deque_append(&res,
			new_str_t_n(token_node->type, filename_node->content));
		filename_node = filename_node->next;
	}
	ft_deque_destroy_list(&filename_expansions, free);
	return (res);
}

/**
 * @brief Performs filename expansion on a deque of tokens.
 *
 * Performes filename expansion on a deque of tokens if appropriate. Only
 * expands token nodes that are of type WORD. Skips operators and nodes that are
 * of type REDIRECTION_WORD and REDIRECTION_DELIMITER. These are expanded (and
 * the potential resulting errors are handled) at the time of redirection.
 *
 * In effect, performed in place.
 *
 * @param tokens The deque of tokens to have filename expansion applied.
 */
void	filename_expand_tokens(t_deque *tokens)
{
	t_deque			new_tokens;
	t_token_node	*token;
	t_deque			expanded_tokens;

	new_tokens = ft_deque_new();
	while (1)
	{
		token = ft_deque_popleft(tokens);
		if (!token)
		{
			break ;
		}
		if (token->type == WORD)
		{
			expanded_tokens = filename_expand_token(token);
			ft_deque_append_deque(&new_tokens, expanded_tokens);
			delete_token_node(token);
		}
		else
		{
			ft_deque_append(&new_tokens, token);
		}
	}
	tokens->head = new_tokens.head;
	tokens->tail = new_tokens.tail;
}

void	filename_expansion(t_deque *tokens)
{
	filename_expand_tokens(tokens);
}

/*
void	str_matches_pattern_tests(void)
{
	printf("-- testing str match glob --\n");
	
	char *a0 = "abc";
	char *p0 = "def";

	printf("\ndoes not match\n");
	printf("str: %s    pat: %s    matches: %i\n", a0, p0,
	str_matches_pattern(a0, p0));

	char *a = "hello world";
	char *b = "helrld";
	char *c = "helrldstuffrld";
	char *d = "helrldrld";

	char *e = "helstuffld";
	char *f = "hestuffrld";
	char *g = "hel";
	char *h = "helrl";
	char *i = "helaa";
	char *j = "helloworlds";
	char *p = "hel*rld";

	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", a, p,
	str_matches_pattern(a, p));
	printf("str: %s    pat: %s    matches: %i\n", b, p,
	str_matches_pattern(b, p));
	printf("str: %s    pat: %s    matches: %i\n", c, p,
	str_matches_pattern(c, p));
	printf("str: %s    pat: %s    matches: %i\n", d, p,
	str_matches_pattern(d, p));
	printf("\ndoes not match\n");
	printf("str: %s    pat: %s    matches: %i\n", e, p,
	str_matches_pattern(e, p));
	printf("str: %s    pat: %s    matches: %i\n", f, p,
	str_matches_pattern(f, p));
	printf("str: %s    pat: %s    matches: %i\n", g, p,
	str_matches_pattern(g, p));
	printf("str: %s    pat: %s    matches: %i\n", h, p,
	str_matches_pattern(h, p));
	printf("str: %s    pat: %s    matches: %i\n", i, p,
	str_matches_pattern(i, p));
	printf("str: %s    pat: %s    matches: %i\n", j, p,
	str_matches_pattern(j, p));

	char *a1 = "astuffb";
	char *b1 = "ab";
	char *c1 = "a1b";
	char *d1 = "a*b";
	char *e1 = "a**b";
	char *f1 = "a***b";
	char *p1 = "a**b";
	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", a1, p1,
	str_matches_pattern(a1, p1));
	printf("str: %s    pat: %s    matches: %i\n", b1, p1,
	str_matches_pattern(b1, p1));
	printf("str: %s    pat: %s    matches: %i\n", c1, p1,
	str_matches_pattern(c1, p1));
	printf("str: %s    pat: %s    matches: %i\n", d1, p1,
	str_matches_pattern(d1, p1));
	printf("str: %s    pat: %s    matches: %i\n", e1, p1,
	str_matches_pattern(e1, p1));
	printf("str: %s    pat: %s    matches: %i\n", f1, p1,
	str_matches_pattern(f1, p1));

	char *a2 = "hello";
	char *b2 = "h";
	char *c2 = "hello world";
	char *d2 = "";
	char *p2 = "hello";
	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", a2, p2,
			str_matches_pattern(a2, p2));
	printf("\ndoes not match\n");
	printf("str: %s    pat: %s    matches: %i\n", b2, p2,
			str_matches_pattern(b2, p2));
	printf("str: %s    pat: %s    matches: %i\n", c2, p2,
			str_matches_pattern(c2, p2));
	printf("str: %s    pat: %s    matches: %i\n", d2, p2,
			str_matches_pattern(d2, p2));

	char *a3 = "hello";
	char *b3 = "helloa";
	char *c3 = "helloworld";
	char *p3 = "hello*";
	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", a3, p3,
			str_matches_pattern(a3, p3));
	printf("str: %s    pat: %s    matches: %i\n", b3, p3,
			str_matches_pattern(b3, p3));
	printf("str: %s    pat: %s    matches: %i\n", c3, p3,
			str_matches_pattern(c3, p3));

	char *a4 = "helloworldfoobar";
	char *b4 = "hellostuffworldstufffoostuffbar";
	char *c4 = "helloworldworldfooworldstufffoobizbar";
	char *p4 = "hello*world*foo*bar";
	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", a4, p4,
			str_matches_pattern(a4, p4));
	printf("str: %s    pat: %s    matches: %i\n", b4, p4,
			str_matches_pattern(b4, p4));
	printf("str: %s    pat: %s    matches: %i\n", c4, p4,
			str_matches_pattern(c4, p4));


	char *a5 = "";
	char *b5 = "stuff";
	char *c5 = "stuffa";
	char *p5 = "s*f";
	printf("\ndoes not match\n");
	printf("str: %s    pat: %s    matches: %i\n", a5, p5,
			str_matches_pattern(a5, p5));
	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", b5, p5,
			str_matches_pattern(b5, p5));
	printf("\ndoes not match\n");
	printf("str: %s    pat: %s    matches: %i\n", c5, p5,
			str_matches_pattern(c5, p5));

	char *a6 = "stuff";
	char *b6 = "";
	char *c6  = "blah";
	char *p6 = "";
	printf("\ndoes not match\n");
	printf("str: %s    pat: %s    matches: %i\n", a6, p6,
			str_matches_pattern(a6, p6));
	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", b6, p6,
			str_matches_pattern(b6, p6));
	printf("\ndoes not match\n");
	printf("str: %s    pat: %s    matches: %i\n", c6, p6,
			str_matches_pattern(c6, p6));

	char *a7 = "foobar";
	char *p7 = "*'oobar'";
	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", a7, p7,
			str_matches_pattern(a7, p7));

	char *a8 = "foobar";
	char *b8 = "*oobar";
	char *p8 = "'*oobar'";
	printf("\ndoes not match\n");
	printf("str: %s    pat: %s    matches: %i\n", a8, p8,
			str_matches_pattern(a8, p8));
	printf("\nmatches\n");
	printf("str: %s    pat: %s    matches: %i\n", b8, p8,
			str_matches_pattern(b8, p8));
}
*/
