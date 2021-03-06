/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:28:06 by msessa            #+#    #+#             */
/*   Updated: 2021/07/15 13:42:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/get_next_line_bonus.h"

int	ft_free_exit(int fd, char *buf[1025], char **line)
{
	free(buf[fd]);
	free(*line);
	buf[fd] = 0;
	*line = 0;
	return (-1);
}

size_t	ft_partial_len(char *buf)
{
	char	*o_buf;

	o_buf = buf;
	while (*buf && *buf != '\n')
		buf++;
	return (buf - o_buf);
}

size_t	ft_strlen(const char *s)
{
	const char	*i;

	i = s;
	while (*i)
		i++;
	return (i - s);
}
