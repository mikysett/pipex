/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/06 18:06:31 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# include "libft.h"
# include "ft_types.h"
# include "ft_init_pipex.h"

// main.c
void	ft_free_exit_failure(t_pipex *pipex, char *msg);
void	ft_set_pipe(t_pipex *pipex);


#endif