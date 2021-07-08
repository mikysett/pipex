/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/08 17:24:06 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUN_CMD_H
#define FT_RUN_CMD_H

void	ft_run_cmd(t_pipex *pipex, int cmd_i);
void	ft_set_cmd_info(t_pipex *pipex, char *cmd_str);
void	ft_exec_cmd_info(t_pipex *pipex);

#endif