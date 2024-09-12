/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:37:49 by sgeiger           #+#    #+#             */
/*   Updated: 2024/09/10 19:09:06 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_input(t_game *game, int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		game->my_error = "Input has to be: \"./cub3d <map.cub>\"\n";
		terminate(game);
	}
	len = ft_strlen(argv[1]);
	if (len <= 4 || ft_strcmp(argv[1] + len - 4, ".cub") != 0)
	{
		game->my_error = "Input file has to be \".cub\"\n";
		terminate(game);
	}
}

char	*get_content_line(t_game *game, char **argv)
{
	int		fd;
	char	*line;
	char	*new_line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		terminate(game);
	while (line == NULL)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			free(line);
			line = NULL;
			continue ;
		}
	}
	new_line = ft_strtrim(line, " \t\r\n");
	free(line);
	return (new_line);
}


void	parser(t_game *game, char **argv)
{
	game->textures->no_texture = NULL;
	game->textures->so_texture = NULL;
	game->textures->ea_texture = NULL;
	game->textures->we_texture = NULL;
	game->textures->ceiling_hex = -1;
	game->textures->floor_hex = -1;

	char	*line;

	line = get_content_line(game, argv);
	if (is_texture(line))
		check_textures(game, line);
	else if (is_color(line))
		check_color(game, line);
	// check_map(); // alloc for flood fill
	// |_> check_chars();
	// |_> is_closed();
}
