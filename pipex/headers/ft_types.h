/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:29:10 by msessa            #+#    #+#             */
/*   Updated: 2021/07/08 17:38:50 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
#define FT_TYPES_H

typedef enum	e_pipe_name
{
	p_curr = 0,
	p_next = 1
}				t_pipe_name;

typedef enum	e_pipe_side
{
	p_read = 0,
	p_write = 1
}				t_pipe_side;

// typedef enum	e_cmd_place
// {
// 	cmd_first,
// 	cmd_curr,
// 	cmd_next,
// 	cmd_last
// }				t_cmd_place;

typedef struct	s_cmd_info
{
	char	*path;
	char	**argv;
}				t_cmd_info;

typedef struct	s_pipex
{
	int			nb_cmd;
	char		**cmd;
	char		*filein;
	int			filein_fd;
	char		*fileout;
	int			fileout_fd;
	bool		here_doc;
	char		*limiter;
	char		**env;
	int			pipes[2][2];
	t_pipe_name	cmd_pipe;
	t_pipe_name	cmd_opposite_pipe;
	t_cmd_info	cmd_info;
}				t_pipex;


#endif