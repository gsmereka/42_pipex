/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:10:10 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/16 17:39:59 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	exit_error(t_data *data);
static void	check_how_much_args(int argc, t_data *data);
static void	check_here_doc(int argc, char **argv, t_data *data);

void	check_args(int argc, char **argv, t_data *data)
{
	check_how_much_args(argc, data);
	check_here_doc(argc, argv, data);
}

static void	check_how_much_args(int argc, t_data *data)
{
	if (argc < 5)
	{
		data->error_msg = ft_strdup("Pipex_bonus needs 4 arguments or more\ntry "
				"'./pipex_bonus file_1 \"cmd_1 flags\" \"cmd_2 flags\" file_2\'\n");
		exit_error(data);
	}
}

static void	check_here_doc(int argc, char **argv, t_data *data)
{
	data->files.here_doc = 0;
	if (ft_strlen(argv[1]) == 8)
	{
		if (ft_strncmp("here_doc", argv[1], 8) == 0)
			data->files.here_doc = 1;
	}
	if (data->files.here_doc == 1 && argc < 6)
	{
		data->error_msg = ft_strdup("Here_doc needs 5 arguments or more\ntry "
				"'./pipex_bonus here_doc LIMITER \"cmd_1\" \"cmd_2\" file_2\'\n"
				"it will simulate: '\"cmd1\" << LIMITER | \"cmd_2\" >> file_2\'\n");
		exit_error(data);
	}
}

static void	exit_error(t_data *data)
{
	write(2, data->error_msg, ft_strlen(data->error_msg));
	free(data->error_msg);
	exit(2);
}
