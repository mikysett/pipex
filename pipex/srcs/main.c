/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:28:53 by msessa            #+#    #+#             */
/*   Updated: 2021/07/14 20:10:48 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	// ft_print_str_arr(envp);
	pipex = ft_init_pipex(argc, argv, envp);
	ft_print_str_arr(pipex->env_path);
	if (pipex->here_doc)
	{

	}
	else
	{
		ft_run_pipex(pipex);
	}
	ft_free_pipex(pipex);
	return (0);
}

void	ft_print_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	printf("Printing str arr:\n");
	if (str_arr)
	{
		while (str_arr[i])
		{
			printf("%d: %s\n", i, str_arr[i]);
			i++;
		}
	}
	printf("END OF PRINTING\n");
}
