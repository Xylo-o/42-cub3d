/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:53:36 by cpuiu             #+#    #+#             */
/*   Updated: 2024/07/13 18:00:19 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

size_t	map_length(t_game *data, int line_index)
{
	size_t	length;

	length = 0;
	while (data->file_content[line_index] != NULL \
			&& !empty_line(data->file_content[line_index]))
	{
		length++;
		line_index++;
	}
	return (length);
}

char	**memory_alloc(char **src, size_t length)
{
	char	**dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char *) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (i < length)
	{
		dest[i] = ft_strdup(src[i]);
		if (dest[i] == NULL)
		{
			while (i > 0)
				free(dest[i--]);
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[length] = NULL;
	return (dest);
}

int	parse_map(t_game *data, int line_index)
{
	size_t	map_len;
	size_t	i;

	map_len = 0;
	while (data->file_content[line_index] != NULL \
			&& !empty_line(data->file_content[line_index]))
		line_index++;
	map_len = map_length(data, line_index);
	data->map = memory_alloc(&data->file_content[line_index], map_len);
	if (data->map == NULL)
		return (EXIT_FAILURE);
	data->tmp = memory_alloc(&data->file_content[line_index], map_len);
	if (data->tmp == NULL)
	{
		i = 0;
		while (data->map[map_len] != NULL)
			free(data->map[map_len++]);
		free(data->map);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}