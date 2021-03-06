/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/15 13:50:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_UTIL_H
# define FT_PIPEX_UTIL_H

void	ft_set_dup(t_pipex *pipex, int dup_from_fd, int dup_to_fd);
void	ft_init_pipe_fd(t_pipex *pipex, int pipe_fd[2]);
int		ft_init_file_fd(char *file, int oflag, int chmod);

#endif
