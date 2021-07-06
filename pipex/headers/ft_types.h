/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/06 17:13:02 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
#define FT_TYPES_H

typedef enum	e_pipe_side
{
	p_read,
	p_write
}				t_pipe_side;

typedef struct	s_pipex
{
	int		nb_cmd;
	char	**cmd;
	char	*filein;
	int		filein_fd;
	char	*fileout;
	int		fileout_fd;
	bool	here_doc;
	char	*limiter;
	char	**env;
	int		pipe_fd[2];
}				t_pipex;

#endif