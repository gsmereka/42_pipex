/* ************************************************************************** */
/*					                                                        */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:18:39 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/16 22:29:56 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	free_cmd_args(t_data *data);
static void	free_list(void **list);

void	finalize(char *msg, int stat, t_data *data)
{
	if (stat != 127 && stat != 0)
		perror(msg);
	else
		write(2, msg, ft_strlen(msg));
	free_program_memory(data);
	exit(stat);
}

void	end_of_program(t_data *data)
{
	int	exit_code;
	int	i;

	i = 0;
	while (i < data->n_cmds)
	{
		waitpid(data->process.pid[i], &data->process.status[i], WUNTRACED);
		i++;
	}
	exit_code = WEXITSTATUS(data->process.status[data->n_cmds - 1]);
	free_program_memory(data);
	exit(exit_code);
}

void	free_program_memory(t_data *data)
{
	if (data->cmd)
		free_list((void *)data->cmd);
	if (data->cmd_arg)
		free_cmd_args(data);
	if (data->paths)
		free_list((void *)data->paths);
	if (data->files.pipes)
		free_list((void *)data->files.pipes);
	if (data->error_msg)
		free(data->error_msg);
	if (data->process.pid && data->process.status)
	{
		free(data->process.pid);
		free(data->process.status);
	}
	if (data->files.here_doc == 1 && data->files.here_doc_pipe)
		free(data->files.here_doc_pipe);
}

static void	free_cmd_args(t_data *data)
{
	int	n_cmds;
	int	i;

	i = 0;
	n_cmds = data->n_cmds;
	while (i < n_cmds)
	{
		if (data->cmd_arg[i])
			free_list((void *)data->cmd_arg[i]);
		i++;
	}
	free(data->cmd_arg);
}

static void	free_list(void **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}
