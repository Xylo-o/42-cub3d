/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:17:30 by cpuiu             #+#    #+#             */
/*   Updated: 2024/07/15 17:27:33 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void validate_map(t_game *data)
{
	int i;

	i = 0;
	while (data->map[i] != NULL)
	{
		if (is_map_line(data->map[i]) == 1 || !empty_line(data->map[i]))
		{
			printf("Error, invalid map.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'N' && *line != 'S'
			&& *line != 'E' && *line != 'W' && *line != ' ' && *line != '\t'
			&& *line != '\n')
			return (1);
		line++;
	}
	return (0);
}

void	check_dimensions(t_game *data)
{
	int i;
	int j;
	int highest;

	i = 0;
	highest = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
			j++;
		if (j > 30)
		{
			printf("Error, map is too wide.\n");
			exit(EXIT_FAILURE);
		}
		i++;
		if (j > highest)
			highest = j;
		if (i > 30)
		{
			printf("Error, map is too tall.\n");
			exit(EXIT_FAILURE);
		}
		data->map_width = highest;
		data->map_height = i;
	}
}