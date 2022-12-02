/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:19:58 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/28 16:06:59 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static char	*path_finder(char *envp[]);

void	set_pathfinder(char *envp[], t_data *data)
{
	char	*path_list;

	path_list = path_finder(envp);
	data->paths = ft_split(path_list, ':');
	if (!data->paths)
		finalize("Environment pointer have not a PATH", 2, data);
}

static char	*path_finder(char *envp[])
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
		i++;
	}
	return (envp[i] + 5);
}
