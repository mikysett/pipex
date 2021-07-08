/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:28:53 by msessa            #+#    #+#             */
/*   Updated: 2021/07/08 17:53:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_run_pipex(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < p->nb_cmd)
	{
		ft_set_cmd_pipes(p, i);
		if (i == 0)
		{
			ft_init_pipe_fd(p, p->pipes[p->cmd_pipe]);
			if (p->filein_fd == STDIN_FILENO)
			{
				i++;
				if (close(p->filein_fd) == -1
					|| close(p->pipes[p->cmd_pipe][p_write]) == -1)
					perror("pipex");
				continue;
			}
			ft_set_dup(p, p->filein_fd, STDIN_FILENO);
			ft_set_dup(p,
				p->pipes[p->cmd_pipe][p_write],
				STDOUT_FILENO);
		}
		else
		{
			ft_init_pipe_fd(p, p->pipes[p->cmd_pipe]);
			ft_set_dup(p,
				p->pipes[p->cmd_opposite_pipe][p_read],
				STDIN_FILENO);
			ft_set_dup(p,
				p->pipes[p->cmd_pipe][p_write],
				STDOUT_FILENO);
		}
		if (i + 1 == p->nb_cmd)
		{
			ft_set_dup(p,
				p->fileout_fd,
				STDOUT_FILENO);
		}

		ft_run_cmd(p, i);
		
		if (i == 0)
		{
			if (close(p->filein_fd) == -1
				|| close(p->pipes[p->cmd_pipe][p_write]) == -1)
				perror("pipex");
		}
		else if (i + 1 == p->nb_cmd)
		{
			if (close(p->pipes[p->cmd_opposite_pipe][p_read]) == -1
				|| close(p->fileout_fd) == -1)
				perror("pipex");
		}
		else
		{
			if (close(p->pipes[p->cmd_opposite_pipe][p_read]) == -1
				|| close(p->pipes[p->cmd_pipe][p_write]) == -1)
				perror("pipex");
		}
		i++;
	}
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
