/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:28:53 by msessa            #+#    #+#             */
/*   Updated: 2021/07/14 01:39:01 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_run_pipex(t_pipex *p)
{
	int	i;

	i = 0;
	ft_set_first_read_pipe(p);
	while (i < p->nb_cmd)
	{
		ft_set_cmd_pipes(p, i);
		if (ft_init_io(p, i))
		{
			ft_run_cmd(p, i);
			ft_close_io(p, i);
		}
		i++;
	}
}

void	ft_set_first_read_pipe(t_pipex *p)
{
	p->pipes[p_next][p_read] = p->filein_fd;
}

void	ft_set_cmd_pipes(t_pipex *pipex, int cmd_index)
{
	if (cmd_index % 2 == 0)
	{
		pipex->cmd_pipe = p_curr;
		pipex->cmd_opposite_pipe = p_next;
	}
	else
	{
		pipex->cmd_pipe = p_next;
		pipex->cmd_opposite_pipe = p_curr;
	}
}

bool	ft_init_io(t_pipex *p, int cmd_index)
{
	ft_init_pipe_fd(p, p->pipes[p->cmd_pipe]);
	if (cmd_index == 0 && p->filein_fd == STDIN_FILENO)
	{
		if (close(p->filein_fd) == -1
			|| close(p->pipes[p->cmd_pipe][p_write]) == -1)
			perror("pipex");
		return (false);
	}
	ft_set_dup(p, p->pipes[p->cmd_opposite_pipe][p_read], STDIN_FILENO);
	if (cmd_index + 1 == p->nb_cmd)
		ft_set_dup(p, p->fileout_fd, p->pipes[p->cmd_pipe][p_write]);
	ft_set_dup(p, p->pipes[p->cmd_pipe][p_write], STDOUT_FILENO);
	return (true);
}

// TODO create ft_invalid_io to check for both filein and fileout invalid files

// bool	ft_init_first_io(t_pipex *p)
// {
// 	if (p->filein_fd == STDIN_FILENO)
// 	{
// 		if (close(p->filein_fd) == -1
// 			|| close(p->pipes[p->cmd_pipe][p_write]) == -1)
// 			perror("pipex");
// 		return (false);
// 	}
// 	return (true);
// }

void	ft_close_io(t_pipex *p)
{
	if (close(p->pipes[p->cmd_opposite_pipe][p_read]) == -1
		|| close(p->pipes[p->cmd_pipe][p_write]) == -1)
		perror("pipex");
}
