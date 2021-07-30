/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:25:55 by msessa            #+#    #+#             */
/*   Updated: 2021/07/30 16:49:11 by msessa           ###   ########.fr       */
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
	ft_init_io_fd(pipex);
	return (pipex);
}

void	ft_set_env(t_pipex *pipex, char **envp)
{
	int	i;

	i = 0;
	pipex->env = envp;
	pipex->env_path = NULL;
	while (pipex->env[i])
	{
		if (!ft_strncmp(pipex->env[i], "PATH=", 5))
		{
			pipex->env_path = ft_split(&pipex->env[i][5], ':');
			break ;
		}
		i++;
	}
}

void	ft_set_cmd(t_pipex *pipex, char **argv)
{
	if (pipex->here_doc)
		pipex->cmd = argv + 3;
	else
		pipex->cmd = argv + 2;
	pipex->cmd_info.path = NULL;
	pipex->cmd_info.argv = NULL;
}

void	ft_set_files(t_pipex *pipex, int argc, char **argv)
{
	if (pipex->here_doc)
		pipex->filein = NULL;
	else
		pipex->filein = argv[1];
	pipex->fileout = argv[argc - 1];
}

void	ft_init_io_fd(t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->fileout_fd = ft_init_file_fd(pipex->fileout,
				O_CREAT | O_APPEND | O_WRONLY, 0644);
	else
	{
		pipex->filein_fd = ft_init_file_fd(pipex->filein, O_RDONLY, 0);
		pipex->fileout_fd = ft_init_file_fd(pipex->fileout,
				O_CREAT | O_TRUNC | O_WRONLY, 0644);
	}
}
