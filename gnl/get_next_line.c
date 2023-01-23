/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 08:24:45 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/11/19 13:50:08 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_once(char **save, int fd)
{
	char	*buffer;
	int		status;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (-1);
	status = read(fd, buffer, BUFFER_SIZE);
	if (status < 0)
	{
		free(buffer);
		return (-1);
	}
	buffer[status] = '\0';
	*save = ft_strjoin(save, buffer);
	free(buffer);
	return (status);
}

char	*get_oneline(char **save)
{
	char	*line;
	int		line_len;

	if (*save == 0)
		return (0);
	line_len = ft_strchr(*save, '\n');
	if ((*save)[line_len] == '\n')
		line_len++;
	if (line_len == 0)
		return (0);
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (line == 0)
	{
		free(*save);
		*save = 0;
		return (0);
	}
	ft_memcpy(line, *save, line_len);
	line[line_len] = '\0';
	return (line);
}

void	update_save(char **save)
{
	char	*new_save;
	int		total_len;
	int		remove_len;

	if (*save == 0)
		return ;
	if (**save == '\0')
	{
		free(*save);
		*save = 0;
		return ;
	}
	total_len = ft_strchr(*save, '\0');
	remove_len = ft_strchr(*save, '\n');
	if ((*save)[remove_len] == '\n')
		remove_len++;
	new_save = (char *)malloc(sizeof(char) * (total_len - remove_len + 1));
	ft_memcpy(new_save, *save + remove_len, total_len - remove_len + 1);
	free(*save);
	*save = new_save;
}

char	*get_next_line(int fd)
{
	static char	*save[FD_MAX];
	char		*line;
	int			read_status;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (0);
	while (1)
	{
		if (in_newline(save[fd]))
			break ;
		read_status = read_once(&save[fd], fd);
		if (read_status == -1)
		{
			if (save[fd] != 0)
				free(save[fd]);
			return (0);
		}
		else if (read_status == 0)
			break ;
	}
	line = get_oneline(&save[fd]);
	update_save(&save[fd]);
	return (line);
}
