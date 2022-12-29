/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:02:22 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/29 14:03:37 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_files
{
	int		here_doc;
	int		*here_doc_pipe;
	int		infile_fd;
	int		outfile_fd;
	char	*infile;
	char	*outfile;
	int		**pipes;
}	t_files;

typedef struct s_process
{
	int		*status;
	int		*pid;
}	t_process;

typedef struct s_data
{
	t_process	process;
	t_files		files;
	char		***cmd_arg;
	char		**cmd;
	char		**paths;
	int			n_cmds;
	char		*error_msg;
}	t_data;

#endif
