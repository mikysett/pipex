/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:28:53 by msessa            #+#    #+#             */
/*   Updated: 2021/07/06 18:05:51 by msessa           ###   ########.fr       */
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
		ft_set_pipe(pipex);
	}
	free(pipex);
	return (0);
}

void	ft_free_exit_failure(t_pipex *pipex, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	if (pipex)
		free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_set_pipe(t_pipex *pipex)
{
	if (dup2(pipex->filein_fd, STDIN_FILENO) == -1
		|| dup2(pipex->pipe_fd[p_write], STDOUT_FILENO) == -1)
	{
		perror("pipex");
		ft_free_exit_failure(pipex, NULL);
	}
}