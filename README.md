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

---


# minishell

A bash shell implementation built as part of the [42 School](https://www.42adel.org.au/) curriculum. `minishell` replicates core bash functionality including built-in commands, environment variable expansion, pipes, redirections, and signal handling.

This project is written in C and provides a functional command-line interface similar to bash.

---

## 🚀 Features

- **Built-in Commands**: echo, cd, pwd, export, unset, env, exit
- **Environment Variable Expansion**: Handles `$VAR` syntax
- **Quoting**: Single and double quote support
- **Pipes**: Command chaining with `|`
- **Redirections**: Input/output redirection (`>`, `<`, `>>`, `<<`)
- **Heredocs**: Multi-line input with `<<`
- **Signal Handling**: Ctrl-C, Ctrl-D, Ctrl-\
- **Interactive Shell**: Real-time command execution

---

## 🖥️ Example Usage

```bash
$ ./minishell
minishell$ echo "Hello, World!"
Hello, World!
minishell$ ls -la
total 8
drwxr-xr-x  2 user user 4096 Jan 15 10:00 .
drwxr-xr-x 10 user user 4096 Jan 15 10:00 ..
-rw-r--r--  1 user user  123 Jan 15 10:00 file.txt
minishell$ cat < file.txt | grep "search"
minishell$ export MY_VAR="Hello"
minishell$ echo $MY_VAR
Hello
minishell$ exit
```

---

## 🚀 Getting Started

### Prerequisites

- `gcc`
- `make`
- `Linux`

### Building

```bash
git clone https://github.com/tasmanday/minishell.git
cd minishell
make
```

### Running

```bash
./minishell
```

### Cleaning

```bash
make fclean
```

---

## 📋 Built-in Commands

| Command | Options | Description |
|:--------:|:--------:|:--------|
| `echo` | `-n` | Print text with optional newline suppression |
| `cd` | path | Change directory (relative or absolute path) |
| `pwd` | none | Print working directory |
| `export` | none | Export environment variables |
| `unset` | none | Unset environment variables |
| `env` | none | Display environment variables |
| `exit` | none | Exit the shell |

---

## �� Supported Features

### Environment Variables
- Expand variables using `$VAR` syntax
- Set and unset environment variables
- Export variables to child processes

### Quoting
- **Single quotes**: Literal text, no expansion
- **Double quotes**: Allow variable expansion
- Handles nested quotes appropriately

### Redirections
- `>` : Output redirection (overwrite)
- `>>` : Output redirection (append)
- `<` : Input redirection
- `<<` : Heredoc (multi-line input)

### Pipes
- Chain commands with `|`
- Support for multiple pipes in sequence
- Proper file descriptor management

### Signal Handling
- **Ctrl-C (SIGINT)**: Interrupt current command
- **Ctrl-D (EOF)**: Exit shell gracefully
- **Ctrl-\ (SIGQUIT)**: Quit with core dump

---

## �� How It Works

- **Lexical Analysis**: Parse input into tokens
- **Command Parsing**: Identify built-ins vs external commands
- **Environment Management**: Handle variable expansion and inheritance
- **Process Management**: Fork and execute commands
- **File Descriptor Management**: Handle pipes and redirections
- **Signal Handling**: Manage shell and child process signals

---

## 🛠️ Made With

C
