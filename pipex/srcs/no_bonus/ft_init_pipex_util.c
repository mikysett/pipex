/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:31:50 by msessa            #+#    #+#             */
/*   Updated: 2021/07/06 11:41:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_nb_cmd(t_pipex *pipex, int argc, char **argv)
{
	if (argc != 5 || !argv)
		ft_free_exit_failure(pipex, "pipex: wrong argument number\n");
	pipex->nb_cmd = 2;
}

void	ft_set_here_doc(t_pipex *pipex, int argc, char **argv)
{
	if (argc < 3 || !argv)
		ft_free_exit_failure(pipex, "pipex: wrong argument number\n");
	pipex->here_doc = false;
}