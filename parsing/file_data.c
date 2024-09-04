/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:42:39 by cpuiu             #+#    #+#             */
/*   Updated: 2024/07/13 17:58:45 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int count_file_lines(char *path)
{
	int fd;
	char *line;
	int lines;

	fd = open(path, O_RDONLY);
	lines = 0;
	if (fd < 0)
	{
		printf("File does not exist, please check the path and file name again.\n");
		exit(-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void read_file_data(char *path, t_game *data)
{
	int i;
	int fd;
	int lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("File does not exist, please check the path and file name again.\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	lines = count_file_lines(path);
	if (lines < 0)
	{
		close(fd);
		printf("Error, empty file.\n");
		exit(EXIT_FAILURE);
	}
	data->file_content = ft_calloc(lines + 1, sizeof(char *));
	if (data->file_content == NULL)
	{
		close(fd);
		printf("Error, memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		data->file_content[i] = get_next_line(fd);
		if (data->file_content[i] == NULL)
		{
			printf("Error: Failed to read line from file.\n");
			close(fd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	data->file_content[lines] = NULL;
	if (close(fd) < 0)
	{
		fprintf(stderr, "Error: Unable to close file '%s'\n", path);
		exit(EXIT_FAILURE);
	}
}