/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:25:55 by msessa            #+#    #+#             */
/*   Updated: 2021/07/08 17:23:03 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_run_cmd(t_pipex *pipex, int cmd_i)
{
	pid_t	child_pid;
	int		wstatus;

	ft_set_cmd_info(pipex, pipex->cmd[cmd_i]);
	if (access(pipex->cmd_info.path, F_OK | X_OK) == -1)
		perror(pipex->cmd_info.path);
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("pipex");
			ft_free_exit_failure(pipex, NULL);
		}
		if (child_pid == 0)
			ft_exec_cmd_info(pipex);
		if (wait(&wstatus) == -1)
		{
			perror("pipex");
			ft_free_exit_failure(pipex, NULL);
		}
		// TODO this may show an error message with "success"
		if (!WIFEXITED(wstatus) || WEXITSTATUS(wstatus) != EXIT_SUCCESS)
		{
			perror("wstatus");
			// ft_free_exit_failure(pipex, NULL);
		}
	}
	ft_free_cmd_info(&pipex->cmd_info);
}

void	ft_set_cmd_info(t_pipex *pipex, char *cmd_str)
{
	int	cmd_path_size;

	pipex->cmd_info.argv = ft_split(cmd_str, ' ');
	if (pipex->cmd_info.argv[0] == NULL)
		pipex->cmd_info.path = NULL;
	else
	{
		cmd_path_size = ft_strlen("/bin/")
			+ ft_strlen(pipex->cmd_info.argv[0]) + 1;
		pipex->cmd_info.path = ft_calloc(cmd_path_size, sizeof(char));
		if (!pipex->cmd_info.path)
			ft_free_exit_failure(pipex, "pipex: can't allocate memory\n");
		ft_strlcat(pipex->cmd_info.path, "/bin/", cmd_path_size);
		ft_strlcat(pipex->cmd_info.path,
			pipex->cmd_info.argv[0], cmd_path_size);
	}
}

void	ft_exec_cmd_info(t_pipex *pipex)
{
	if (execve(pipex->cmd_info.path,
		pipex->cmd_info.argv, pipex->env) == -1)
	{
		perror("pipex:");
		ft_free_exit_failure(pipex, NULL);
	}
}
