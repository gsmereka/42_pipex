/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:01:54 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/16 21:17:55 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "./objects_bonus.h"
# include "./utils.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

// check_args
void	check_args(int argc, char **argv, t_data *data);

// parse_args
void	arg_parser(char **argv, t_data *data);

// set_cmds
int		set_cmds(t_data *data);

// finalize
void	finalize(char *msg, int stat, t_data *data);
void	end_of_program(t_data *data);
void	free_program_memory(t_data *data);

// initialize
int		initialize(int argc, char **argv, t_data *data);

// redirection
void	redirect_input(int cmd, t_data *data);
void	redirect_output(int cmd, t_data *data);

// processes
int		set_processes(t_data *data);

// execute
void	execute(int cmd, char **cmd_args, t_data *data);

// set_pathfinder
void	set_pathfinder(char *envp[], t_data *data);

// here_doc
void	set_here_doc(char **argv, t_data *data);

// gnl
char	*get_next_line(int fd, int stop);

#endif
