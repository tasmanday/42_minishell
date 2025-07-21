# minishell

A bash shell implementation built as part of the [42 School](https://www.42adel.org.au/) curriculum. `minishell` replicates core bash functionality including built-in commands, environment variable expansion, pipes, redirections, and signal handling.

This project is written in C and provides a functional command-line interface similar to bash.

---

## 🚀 Features

### Core Functionality
- **Built-in Commands**: echo, cd, pwd, export, unset, env, exit
- **Environment Variable Expansion**: Handles `$VAR` syntax with full quoting support
- **Command Chaining**: Pipes (`|`) for command composition
- **File Redirections**: Input/output redirection (`>`, `<`, `>>`, `<<`)
- **Heredocs**: Multi-line input processing
- **Signal Handling**: Ctrl-C, Ctrl-D, Ctrl-\ with proper cleanup
- **Interactive Shell**: Real-time command execution with prompt

### Advanced Features
- **Quoting System**: Single quotes (literal) and double quotes (with expansion)
- **Process Management**: Proper fork/exec with signal inheritance
- **File Descriptor Management**: Automatic cleanup and redirection
- **Error Handling**: Graceful error recovery and meaningful messages

---

## 🚀 Getting Started

### Prerequisites

- `gcc` (GNU Compiler Collection)
- `make` (Build automation tool)
- `Linux` (Tested on Ubuntu/Debian)

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

## 🖥️ Usage Examples

```bash
# Basic functionality
echo "Hello World"
cd /tmp && pwd

# Environment variables
export TEST_VAR="test"
echo $TEST_VAR

# Pipes and redirections
echo "test" | grep "test"
echo "hello" > test.txt
cat < test.txt

# Signal handling
# Press Ctrl-C to test interrupt handling
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

## ⚙️ Technical Details

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

## ⚡ Architecture

- **Lexical Analysis**: Parse input into tokens
- **Command Parsing**: Identify built-ins vs external commands
- **Environment Management**: Handle variable expansion and inheritance
- **Process Management**: Fork and execute commands
- **File Descriptor Management**: Handle pipes and redirections
- **Signal Handling**: Manage shell and child process signals

---

## 📋 Project Limitations

### Compilation Requirements
- **Compiler Flags**: Must compile with `-Wall -Wextra -Werror`
- **No Re-linking**: Makefile must not re-link unnecessarily
- **Error-Free Compilation**: No compilation errors or warnings allowed

### Code Restrictions
- **Global Variables**: Limited to one global variable for signal handling only
- **Authorized Libraries**: Only `libft` (our custom library) is allowed
- **External Functions**: Limited to specific authorized functions only

### Allowed External Functions
- **Interactive Input**: `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`
- **Standard I/O**: `printf`, `write`, `access`, `open`, `read`, `close`
- **Memory Management**: `malloc`, `free`
- **Process Control**: `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`
- **File System**: `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`
- **File Descriptors**: `dup`, `dup2`, `pipe`
- **Directory Operations**: `opendir`, `readdir`, `closedir`
- **Error Handling**: `strerror`, `perror`
- **Terminal Control**: `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`
- **Terminal Capabilities**: `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

### Makefile Requirements
- **Required Targets**: `NAME`, `all`, `clean`, `fclean`, `re`
- **Submission Files**: `Makefile`, `*.h`, `*.c`

---

## 🛠️ Made With

- **C** - Core implementation language
- **Make** - Build system
- **Linux** - Target platform
- **libft** - Custom C library for utility functions

---

## 🤝 Contributors

- [Andrew](https://github.com/valedictum)
- [Tasman](https://github.com/tasmanday)
