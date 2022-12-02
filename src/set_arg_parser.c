/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:53:10 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/01 13:01:49 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static char	**parse_args(char *old_args);
static char	*hide_spaces_between(char *old_arg, char c);
static char	*clean_quotes(char *old_arg);
static char	**set_spaces_back(char **args);

void	arg_parser(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_cmds)
	{
		data->cmd_arg[i] = parse_args(argv[i + 2]);
		if (!data->cmd_arg[i])
			finalize("Failed to allocate memory for arguments", 12, data);
		i++;
	}
}

static char	**parse_args(char *old_args)
{
	char	*temp_args;
	char	**new_args;

	temp_args = ft_strdup(old_args);
	temp_args = hide_spaces_between(temp_args, '"');
	temp_args = hide_spaces_between(temp_args, '\'');
	temp_args = clean_quotes(temp_args);
	new_args = ft_split(temp_args, ' ');
	new_args = set_spaces_back(new_args);
	if (temp_args != NULL)
		free(temp_args);
	return (new_args);
}

static char	*hide_spaces_between(char *old_arg, char c)
{
	int	i;

	i = 0;
	if (!old_arg)
		return (NULL);
	while (old_arg[i])
	{
		if (old_arg[i] == c)
		{
			while (old_arg[i + 1] != c && old_arg[i + 1] != '\0')
			{
				if (old_arg[i + 1] == ' ')
					old_arg[i + 1] = 1;
				i++;
			}
		}
		i++;
	}
	return (old_arg);
}

static char	*clean_quotes(char *old_arg)
{
	int	i;

	i = 0;
	if (!old_arg)
		return (NULL);
	while (old_arg[i])
	{
		if (old_arg[i] == ' ')
		{
			if (old_arg[i - 1] == '\'' || old_arg[i - 1] == '"')
				old_arg[i - 1] = ' ';
			if (old_arg[i + 1] == '\'' || old_arg[i + 1] == '"')
			{
				old_arg[i + 1] = ' ';
				i++;
			}
		}
		i++;
	}
	if (old_arg[i - 1] == '\'' || old_arg[i - 1] == '"')
		old_arg[i - 1] = ' ';
	return (old_arg);
}

static char	**set_spaces_back(char **args)
{
	int	i;
	int	j;

	i = 0;
	if (args == NULL)
		return (NULL);
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == 1)
				args[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (args);
}
