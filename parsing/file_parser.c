/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:51:42 by cpuiu             #+#    #+#             */
/*   Updated: 2024/07/15 17:17:11 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void parse_file_data(t_game *data)
{
	int line_index;
	int empty_line_count;

	line_index = 0;
	empty_line_count = 0;
	while (data->file_content[line_index] != NULL)
	{
		if (empty_line(data->file_content[line_index]))
			empty_line_count++;
		if (empty_line_count == 6)
			break ;
		line_index++;
	}
	if (parse_textures_paths(data, ++line_index) == 0)
	{
		parse_map(data, line_index);
		validate_map(data);
	}
	else
	{
		printf("Error, Textures needed weren't provided.\n");
		exit(EXIT_FAILURE);
	}
}
