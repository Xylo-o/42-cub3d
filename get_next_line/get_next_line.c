/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:29:38 by cpuiu             #+#    #+#             */
/*   Updated: 2024/07/16 17:37:19 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *start_line)
{
	int		i;
	char	*line;

	if (!start_line || !start_line[0])
		return (NULL);
	i = 0;
	while (start_line[i] && start_line[i] != '\n')
		i++;
	if (start_line[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (start_line[i] && start_line[i] != '\n')
	{
		line[i] = start_line[i];
		i++;
	}
	if (start_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_new_start(char *start)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i = i + (start[i] == '\n');
	buff = (char *)malloc(sizeof(char) *(ft_strlen(start) + 1));
	if (!buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		buff[j] = start[i + j];
		j++;
	}
	buff[j] = '\0';
	free(start);
	return (buff);
}

int	read_buffer(char *buffer, char **rem, int fd)
{
	int			bytes_read;
	char		*merged_str;

	bytes_read = 1;
	while (!(ft_strchr(*rem, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		buffer[bytes_read] = '\0';
		merged_str = ft_strjoin(*rem, buffer);
		free(*rem);
		*rem = merged_str;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!rem)
		rem = ft_strdup("");
	if (read_buffer(buffer, &rem, fd) == 0)
		return (free(rem), free(buffer), buffer = NULL, rem = NULL);
	free(buffer);
	buffer = NULL;
	buffer = ft_read_line(rem);
	rem = ft_new_start(rem);
	return (buffer);
}
