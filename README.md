# 42_minishell

minishell is a replication of a bash shell.

to run it, clone this repository, then run the "make" command, and then execute the minishell executable with "./minishell".
when you're done "make fclean" will clean everything up.

it includes the builtins:
- echo with option -n
- cd with only a relative or absolute path
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options

it can expand environmental variables and handle single and double quotes but it doesn't need to be able to handle unclosed quotes or special characters like backslash and semicolon.

it also can handle pipes and redirections including heredocs (<<), and the ctrl-C, ctrl-D, & ctrl-\ signals.

