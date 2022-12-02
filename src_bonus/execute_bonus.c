/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:17:43 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/01 20:45:34 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

static void	close_fds_at_error(int cmd, t_data *data);

void	execute(int cmd, char *const argv[], t_data *data)
{
	int		exec;

	exec = execve(data->cmd[cmd], argv, NULL);
	if (exec == -1)
	{
		close_fds_at_error(cmd, data);
		data->error_msg = ft_strjoin(ft_strdup(data->cmd_arg[cmd][0]),
				": command not found\n");
		finalize(data->error_msg, 127, data);
	}
}

static void	close_fds_at_error(int cmd, t_data *data)
{
	if (cmd == data->n_cmds - 1 && data->files.outfile_fd != -1)
		close(data->files.outfile_fd);
	if (data->files.infile_fd != -1)
		close(data->files.infile_fd);
	if (cmd > 0)
		close(data->files.pipes[cmd - 1][0]);
	close(data->files.pipes[cmd][1]);
	close(data->files.pipes[cmd][0]);
	close(1);
	close(0);
}
