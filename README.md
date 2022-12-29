# 42_pipex

The goal of this project is to simulate the functioning of the pipe in bash using C.

## About the project

This project simulates the behavior of the bash command "cmd_1 < file_1 | cmd_2 > file_2", where each "cmd" is a command that will be executed by bash, and the "|" symbol indicates that the command to the left will be connected to the command to the right, forming a "chain" or "pipeline" of commands. The notation "cmd_1 < file_1" and "> file_2" indicates that the "file_1" file will be used as input for the first command and the "file_2" file will be used as the output of the last command in the chain.

It is possible to add as many commands as desired to the chain. We use the standard libft function library to organize the arguments and create a process for each command argument, executing them with the execve() function. In addition, we communicate between processes and files using the pipe() and dup2() functions. Feel free to contribute or make suggestions for improvements.

## How to use

To use the "pipex" program, follow these steps:

1. Execute the "make" command to create the executable "pipex".
2. Execute the command "./pipex <file_1> <cmd_1> <cmd_2> <file_2>".
   - The "file_1" and "file_2" files can be any file.
   - The "cmd_1" and "cmd_2" commands can be any bash command.
   - It is possible to add as many commands as desired to the command chain, just follow the same format.

## Other features

This project also allows you to easily and conveniently simulate the use of the "<<" and ">>" operators, simulating the following bash behavior: "cmd_1 << EOF | cmd_2 >> file".

The "<<" operator (here document) is a data input mechanism that allows the user to provide a series of text lines as input to a command through the standard input of bash. You need to use a "EOF" string to indicate the end of the reading, but this string can be anything.

The ">>" operator represents the redirection of the standard output of bash to a file. The difference with respect to the ">" operator is that ">>" adds the content to the end of the file, instead of replacing the existing content with the result of the command.

## Examples

* $> ./pipex infile "ls -l" "wc -l" outfile
	- Should behave like: < infile ls -l | wc -l > outfile

* $> ./pipex infile "grep a1" "wc -w" outfile
	- Should behave like: < infile grep a1 | wc -w > outfile

* $> ./pipex infile "grep a1" "wc -w" cat cat cat cat outfile
	- Should behave like: < infile grep a1 | wc -w | cat | cat | cat | ls > outfile

* $> ./pipex here_doc EOF "cat" "wc -l" outfile
	- Should behave like: cat << EOF | wc -l >> outfile

* $> ./pipex here_doc EOF "cat" "cat" outfile
	- Should behave like: cat << EOF | cat >> outfile

* $> ./pipex here_doc EOF "cat" "wc -l" cat cat outfile
	- Should behave like: cat << EOF | wc -l | cat | cat >> outfile