/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_first_read_pipe.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:27:47 by msessa            #+#    #+#             */
/*   Updated: 2021/07/15 13:35:46 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "bonus/get_next_line_bonus.h"

static void	ft_save_user_input(t_pipex *p);

void	ft_set_first_read_pipe(t_pipex *p)
{
	if (!p->here_doc)
		p->pipes[p_next][p_read] = p->filein_fd;
	else
	{
		ft_init_pipe_fd(p, p->pipes[p_curr]);
		ft_save_user_input(p);
		if (close(p->pipes[p_curr][p_write]) == -1)
			perror("pipex");
		ft_set_dup(p, p->pipes[p_curr][p_read], STDIN_FILENO);
	}
}

static void	ft_save_user_input(t_pipex *p)
{
	char		*line;
	const int	limiter_mem_size = ft_strlen(p->limiter) + 1;

	write(STDOUT_FILENO, "here_doc> ", 10);
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!ft_strncmp(p->limiter, line, limiter_mem_size))
		{
			if (close(STDIN_FILENO) == -1)
				perror("pipex");
			free(line);
			break ;
		}
		write(p->pipes[p_curr][p_write], line, ft_strlen(line));
		write(p->pipes[p_curr][p_write], "\n", 1);
		free(line);
		write(STDOUT_FILENO, "here_doc> ", 10);
	}
}
