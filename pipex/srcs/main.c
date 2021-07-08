/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:28:53 by msessa            #+#    #+#             */
/*   Updated: 2021/07/08 17:46:48 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = ft_init_pipex(argc, argv, envp);
	if (pipex->here_doc)
	{

	}
	else
	{
		ft_run_pipex(pipex);
		// while (i < pipex->nb_cmd)
		// {
		// 	if (i == 0)
		// 	{
		// 		ft_init_pipe_fd(pipex, pipex->pipes[p_curr]);
		// 		if (pipex->filein_fd == STDIN_FILENO)
		// 		{
		// 			i++;
		// 			if (close(pipex->filein_fd) == -1
		// 				|| close(pipex->pipes[p_curr][p_write]) == -1)
		// 				perror("pipex");
		// 			continue;
		// 		}
		// 		ft_set_dup(pipex, pipex->filein_fd, STDIN_FILENO);
		// 		ft_set_dup(pipex, pipex->pipes[p_curr][p_write], STDOUT_FILENO);
		// 	}
		// 	else if (i % 2 == 1)
		// 	{
		// 		ft_init_pipe_fd(pipex, pipex->pipes[p_next]);
		// 		ft_set_dup(pipex,
		// 			pipex->pipes[p_curr][p_read],
		// 			STDIN_FILENO);
		// 		ft_set_dup(pipex,
		// 			pipex->pipes[p_next][p_write],
		// 			STDOUT_FILENO);
		// 	}
		// 	else if (i % 2 == 0)
		// 	{
		// 		ft_init_pipe_fd(pipex, pipex->pipes[p_curr]);
		// 		ft_set_dup(pipex,
		// 			pipex->pipes[p_next][p_read],
		// 			STDIN_FILENO);
		// 		ft_set_dup(pipex,
		// 			pipex->pipes[p_curr][p_write],
		// 			STDOUT_FILENO);
		// 	}
		// 	if (i + 1 == pipex->nb_cmd)
		// 	{
		// 		ft_set_dup(pipex,
		// 			pipex->fileout_fd,
		// 			STDOUT_FILENO);
		// 	}

		// 	ft_run_cmd(pipex, i);
			
		// 	if (i == 0)
		// 	{
		// 		if (close(pipex->filein_fd) == -1
		// 			|| close(pipex->pipes[p_curr][p_write]) == -1)
		// 			perror("pipex");
		// 	}
		// 	else if (i + 1 == pipex->nb_cmd)
		// 	{
		// 		if (close(pipex->pipes[p_curr][p_read]) == -1
		// 			|| close(pipex->fileout_fd) == -1)
		// 			perror("pipex");
		// 	}
		// 	else if (i % 2 == 1)
		// 	{
		// 		if (close(pipex->pipes[p_curr][p_read]) == -1
		// 			|| close(pipex->pipes[p_next][p_write]) == -1)
		// 			perror("pipex");
		// 	}
		// 	else if (i % 2 == 0)
		// 	{
		// 		if (close(pipex->pipes[p_next][p_read]) == -1
		// 			|| close(pipex->pipes[p_curr][p_write]) == -1)
		// 			perror("pipex");
		// 	}
		// 	i++;
		// }
	}
	free(pipex);
	return (0);
}
