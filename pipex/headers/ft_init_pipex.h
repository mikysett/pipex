/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/08 14:19:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_PIPEX_H
#define FT_INIT_PIPEX_H

t_pipex	*ft_init_pipex(int argc, char **argv, char **envp);
t_pipex	*ft_calloc_pipex(void);
void	ft_set_env(t_pipex *pipex, char **envp);
void	ft_set_cmd(t_pipex *pipex, char **argv);
void	ft_set_files(t_pipex *pipex, int argc, char **argv);

// ft_init_pipex_util.c
void	ft_set_nb_cmd(t_pipex *pipex, int argc, char **argv);
void	ft_set_here_doc(t_pipex *pipex, int argc, char **argv);

#endif