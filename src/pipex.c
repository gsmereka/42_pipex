/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:01:18 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/29 14:05:55 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	check_args(argc, argv, &data);
	initialize(argc, argv, &data);
	if (data.files.here_doc == 1)
		set_here_doc(argv, &data);
	set_pathfinder(envp, &data);
	arg_parser(argv, &data);
	set_cmds(&data);
	set_processes(&data);
	end_of_program(&data);
}
