/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_here_doc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:01:29 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/02 23:26:08 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

static void	init_here_doc_settings(t_data *data);
static void	init_here_doc(char **argv, t_data *data);
static int	compare_str_with_limiter(char *str, char *limiter, t_data *data);
static int	need_interrupt(char *str, char *limiter);

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
	while (i >= 0)
	{
		write(1, "> ", 2);
		str = get_next_line(0, 0);
		if (need_interrupt(str, argv[2]))
			break ;
		if (compare_str_with_limiter(str, argv[2], data))
			break ;
		write(data->files.here_doc_pipe[1], str, ft_strlen(str));
		free(str);
	}
	get_next_line(0, 1);
	close(data->files.here_doc_pipe[1]);
}

static int	compare_str_with_limiter(char *str, char *argv_lim, t_data *data)
{
	int		diff;
	int		size;
	char	*limiter;

	limiter = ft_strdup(argv_lim);
	limiter = ft_strjoin(limiter, "\n");
	if (!limiter)
	{
		free(str);
		get_next_line(0, 1);
		close(data->files.here_doc_pipe[1]);
		finalize("Error at simulate here_doc", 1, data);
	}
	size = ft_strlen(limiter);
	diff = ft_strncmp(str, limiter, size + 1);
	free(limiter);
	if (diff != 0)
		return (0);
	free(str);
	return (1);
}

static int	need_interrupt(char *str, char *limiter)
{
	char	*msg;

	if (str != NULL)
		return (0);
	msg = ft_strdup("bash: warning: here-document at last line "\
		"delimited by end-of-file (wanted `");
	msg = ft_strjoin(msg, limiter);
	msg = ft_strjoin(msg, "')\n");
	if (msg != NULL)
	{
		write(2, msg, ft_strlen(msg));
		free(msg);
	}
	return (1);
}
