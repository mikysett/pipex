/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/15 13:50:30 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUN_CMD_H
# define FT_RUN_CMD_H

void	ft_run_cmd(t_pipex *pipex, int cmd_i);
void	ft_set_cmd_info(t_pipex *pipex, char *cmd_str);
void	ft_set_cmd_path(t_pipex *p, char *cmd_name);
void	ft_exec_cmd_info(t_pipex *pipex);

#endif