/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipex.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/14 01:39:07 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUN_PIPEX_H
#define FT_RUN_PIPEX_H

void	ft_run_pipex(t_pipex *pipex);
void	ft_set_first_read_pipe(t_pipex *p);
void	ft_set_cmd_pipes(t_pipex *pipex, int cmd_index);
bool	ft_init_io(t_pipex *p, int cmd_index);
// bool	ft_init_first_io(t_pipex *p);
void	ft_close_io(t_pipex *p);

#endif