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

void	check_args(int argc, t_data *data)
{
	if (argc != 5)
	{
		data->error_msg = ft_strdup("Pipex needs exactly 4 arguments \ntry "
				"'./pipex file_1 \"cmd_1 flags\" \"cmd_2 flags\" file_2\'\n");
		write(2, data->error_msg, ft_strlen(data->error_msg));
		free(data->error_msg);
		exit(2);
	}
}
