/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex_util.b                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:31:50 by msessa            #+#    #+#             */
/*   Updated: 2021/07/06 11:41:12 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_nb_cmd(t_pipex *pipex, int argc, char **argv)
{
	if (argc < 5)
		ft_free_exit_failure(pipex, "pipex: wrong argument number\n");
	if (!strcmp(argv[1], "here_doc"))
	{
		pipex->nb_cmd = argc - 4;
		if (pipex->nb_cmd == 0)
			ft_free_exit_failure(pipex,
				"pipex: wrong argument number for here_doc\n");
	}
	else 
		pipex->nb_cmd = argc - 3;
}

void	ft_set_here_doc(t_pipex *pipex, int argc, char **argv)
{
	if (argc < 5)
		ft_free_exit_failure(pipex, "pipex: wrong argument number\n");
	if (!strcmp(argv[1], "here_doc"))
	{
		pipex->here_doc = true;
		pipex->limiter = argv[2];
	}
	else
		pipex->here_doc = false;
}