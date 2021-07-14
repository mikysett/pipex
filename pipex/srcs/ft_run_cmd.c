/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:25:55 by msessa            #+#    #+#             */
/*   Updated: 2021/07/14 20:02:48 by msessa           ###   ########.fr       */
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
	}
	ft_free_cmd_info(&pipex->cmd_info);
}

void	ft_set_cmd_info(t_pipex *pipex, char *cmd_str)
{
	pipex->cmd_info.argv = ft_split(cmd_str, ' ');
	if (pipex->cmd_info.argv[0] == NULL)
		pipex->cmd_info.path = NULL;
	else
		ft_set_cmd_path(pipex, pipex->cmd_info.argv[0]);
}

void	ft_set_cmd_path(t_pipex *p, char *cmd_name)
{
	int	i;
	int	cmd_path_size;
	int	cmd_name_len;

	i = 0;
	cmd_name_len = ft_strlen(cmd_name);
	while (p->env_path[i])
	{
		cmd_path_size = ft_strlen(p->env_path[i])
			+ cmd_name_len + 1;
		p->cmd_info.path = ft_calloc(cmd_path_size, sizeof(char));
		if (!p->cmd_info.path)
			ft_free_exit_failure(p, "pipex: can't allocate memory\n");
		ft_strlcat(p->cmd_info.path, p->env_path[i], cmd_path_size);
		ft_strlcat(p->cmd_info.path, cmd_name, cmd_path_size);
		if (access(p->cmd_info.path, F_OK | X_OK) == 0)
			return ;
		free(p->cmd_info.path);
		p->cmd_info.path = 0;
		i++;
	}
	p->cmd_info.path = ft_strdup(cmd_name);
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
