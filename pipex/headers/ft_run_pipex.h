/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipex.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/14 18:34:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUN_PIPEX_H
#define FT_RUN_PIPEX_H

void	ft_run_pipex(t_pipex *pipex);
void	ft_set_cmd_pipes(t_pipex *pipex, int cmd_index);
bool	ft_init_io(t_pipex *p, int cmd_index);
void	ft_close_io(t_pipex *p);

#endif