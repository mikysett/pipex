/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/15 00:12:30 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_UTIL_H
#define FT_MEMORY_UTIL_H

t_pipex	*ft_calloc_pipex(void);
void	ft_free_exit_failure(t_pipex *pipex, char *msg);
void	ft_free_pipex(t_pipex *pipex);
void	ft_free_cmd_info(t_cmd_info *pipex_cmd_info);

#endif
