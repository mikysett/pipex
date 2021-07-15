/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:28:53 by msessa            #+#    #+#             */
/*   Updated: 2021/07/15 00:11:38 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_calloc_pipex(void)
{
	t_pipex	*pipex;

	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		ft_free_exit_failure(pipex, "pipex: can't allocate memory\n");
	return (pipex);
}

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
