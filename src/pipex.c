/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:01:18 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/01 12:31:47 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

//int execve(const char *pathname, char *const argv[], char *const envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	check_args(argc, &data);
	initialize(argc, argv, &data);
	set_pathfinder(envp, &data);
	arg_parser(argv, &data);
	set_cmds(&data);
	set_processes(&data);
	end_of_program(&data);
}
