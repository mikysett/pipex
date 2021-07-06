/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:25:55 by msessa            #+#    #+#             */
/*   Updated: 2021/07/06 17:19:52 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_init_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = ft_calloc_pipex();
	ft_set_env(pipex, envp);
	ft_set_nb_cmd(pipex, argc, argv);
	ft_set_here_doc(pipex, argc, argv);
	ft_set_cmd(pipex, argv);
	ft_set_files(pipex, argc, argv);
	ft_init_filein_fd(pipex);
	ft_init_pipe_fd(pipex);
	return (pipex);
}

t_pipex	*ft_calloc_pipex(void)
{
	t_pipex	*pipex;

	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		ft_free_exit_failure(pipex, "pipex: can't allocate memory\n");
	return (pipex);
}

void	ft_set_env(t_pipex *pipex, char **envp)
{
	pipex->env = envp;
}

void	ft_set_cmd(t_pipex *pipex, char **argv)
{
	if (pipex->here_doc)
		pipex->cmd = argv + 3;
	else
		pipex->cmd = argv + 2;
}

void	ft_set_files(t_pipex *pipex, int argc, char **argv)
{
	if (pipex->here_doc)
		pipex->filein = NULL;
	else
		pipex->filein = argv[1];
	pipex->fileout = argv[argc - 1];
}

void	ft_init_filein_fd(t_pipex *pipex)
{
	pipex->filein_fd = open(pipex->filein, O_RDONLY);
	if (pipex->filein_fd == -1)
	{
		perror(pipex->filein);
		ft_free_exit_failure(pipex, NULL);
	}
}

void	ft_init_pipe_fd(t_pipex *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("pipex");
		ft_free_exit_failure(pipex, NULL);
	}
}