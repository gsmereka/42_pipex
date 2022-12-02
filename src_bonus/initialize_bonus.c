/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:14 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/01 20:45:34 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

static void	set_config(int argc, t_data *data);
static void	set_cmds_memory(t_data *data);
static int	set_pipes_memory(t_data *data);
static void	set_files_path(int argc, char **argv, t_data *data);

int	initialize(int argc, char **argv, t_data *data)
{
	set_config(argc, data);
	set_cmds_memory(data);
	set_pipes_memory(data);
	set_files_path(argc, argv, data);
	return (0);
}

static void	set_config(int argc, t_data *data)
{
	data->cmd = NULL;
	data->cmd_arg = NULL;
	data->paths = NULL;
	data->files.pipes = NULL;
	data->error_msg = NULL;
	if (data->files.here_doc == 0)
		data->n_cmds = argc - 3;
	if (data->files.here_doc == 1)
		data->n_cmds = argc - 4;
}

static void	set_files_path(int argc, char **argv, t_data *data)
{
	if (data->files.here_doc == 0)
		data->files.infile = argv[1];
	if (data->files.here_doc == 1)
		data->files.infile = NULL;
	data->files.outfile = argv[argc - 1];
}

static void	set_cmds_memory(t_data *data)
{
	data->cmd = ft_calloc(data->n_cmds + 1, sizeof(char *));
	data->cmd_arg = ft_calloc((data->n_cmds), sizeof(char **));
	data->process.status = ft_calloc(data->n_cmds + 1, sizeof(int));
	data->process.pid = ft_calloc((data->n_cmds + 1), sizeof(int));
	if (!data->cmd || !data->cmd_arg)
		finalize("Error allocating memory", 12, data);
	data->cmd[data->n_cmds] = NULL;
}

static int	set_pipes_memory(t_data *data)
{
	int	i;

	i = 0;
	data->files.pipes = ft_calloc((data->n_cmds + 1), (sizeof(int *)));
	if (!data->files.pipes)
		finalize("Error allocating memory", 12, data);
	while (i < data->n_cmds)
	{
		data->files.pipes[i] = ft_calloc(2, sizeof(int));
		if (!data->files.pipes[i])
			finalize("Error allocating memory", 12, data);
		i++;
	}
	data->files.pipes[i] = NULL;
	return (0);
}
