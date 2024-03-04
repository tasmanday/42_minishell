
#include "../../inc/minishell.h"

char	*get_input(t_msh *msh, char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (!line)
	{
		if (isatty(STDIN_FILENO))
			write(2, "exit\n", 5);
		free_everything(msh);
		exit(EXIT_FAILURE); // update to last exit status
	}
	if (line[0] != '\0')
	{
		add_history(line);
	}
	return (line);
}
