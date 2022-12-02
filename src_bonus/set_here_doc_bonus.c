/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_here_doc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:01:29 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/01 22:57:11 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

static int	check_limiter_cmd(char *str, char *limiter, t_data *data);
static void	init_here_doc_settings(t_data *data);
static void	init_here_doc(char **argv, t_data *data);

void	set_here_doc(char **argv, t_data *data)
{
	init_here_doc_settings(data);
	init_here_doc(argv, data);
}

static void	init_here_doc_settings(t_data *data)
{
	data->files.here_doc_pipe = ft_calloc(2, sizeof(int));
	if (!data->files.here_doc_pipe)
		finalize("Fail allocating memory for here_doc", 12, data);
	pipe(data->files.here_doc_pipe);
}

static void	init_here_doc(char **argv, t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (i == 0)
	{
		write(1, "> ", 2);
		str = get_next_line(0, 0);
		if (check_limiter_cmd(str, argv[2], data))
		{
			free(str);
			str = get_next_line(0, 1);
			free(str);
			break ;
		}
		write (data->files.here_doc_pipe[1], str, ft_strlen(str));
		free(str);
	}
	close(data->files.here_doc_pipe[1]);
}

static int	check_limiter_cmd(char *str, char *limiter, t_data *data)
{
	int		diff;
	int		size;
	char	*temp_str;

	if (!str)
		finalize("Error at simulate here_doc", 1, data);
	temp_str = ft_strdup(str);
	if (!temp_str)
		finalize("Error at simulate here_doc", 1, data);
	size = ft_strlen(temp_str) - 1;
	temp_str[size] = '\0';
	diff = ft_strncmp(temp_str, limiter, size);
	free(temp_str);
	if (diff == 0)
		return (1);
	return (0);
}
