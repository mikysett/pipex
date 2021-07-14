/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:28:53 by msessa            #+#    #+#             */
/*   Updated: 2021/07/14 20:11:14 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_exit_failure(t_pipex *pipex, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_free_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	ft_free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		ft_free_cmd_info(&pipex->cmd_info);
		if (pipex->env_path)
			ft_free_str_arr(pipex->env_path);
		free(pipex);
	}
}

void	ft_free_cmd_info(t_cmd_info *pipex_cmd_info)
{
	if (pipex_cmd_info->path)
	{
		free(pipex_cmd_info->path);
		pipex_cmd_info->path = NULL;
	}
	if (pipex_cmd_info->argv)
	{
		ft_free_str_arr(pipex_cmd_info->argv);
		pipex_cmd_info->argv = NULL;
	}
}

void	ft_set_dup(t_pipex *pipex, int dup_from_fd, int dup_to_fd)
{
	if (dup2(dup_from_fd, dup_to_fd) == -1)
	{
		perror("pipex");
		ft_free_exit_failure(pipex, NULL);
	}
}

void	ft_init_pipe_fd(t_pipex *pipex, int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipex");
		ft_free_exit_failure(pipex, NULL);
	}
}

int	ft_init_file_fd(char *file, int oflag, int chmod)
{
	int	file_fd;

	if (chmod)
		file_fd = open(file, oflag, chmod);
	else
		file_fd = open(file, oflag);
	if (file_fd == -1)
	{
		perror(file);
		return (STDIN_FILENO);
	}
	return (file_fd);
}
