/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:42:40 by sgeiger           #+#    #+#             */
/*   Updated: 2024/09/19 21:25:33 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	is_map(t_game *game, char *line)
{
	int	i;

	i = 0;
	(void)game;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1')
	{
		game->map->in_map = true;
		return (true);
	}
	return (false);
}

bool	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

char	*load_map(t_game *game, char *line)
{
	static char	*buf = NULL;
	char		*temp;

	if (!buf)
	{
		buf = (char *)malloc(sizeof(char));
		if (!buf)
			terminate(game);
		buf[0] = '\0';
	}
	temp = ft_strjoin(buf, line);
	if (!temp)
		terminate(game);
	free(line);
	free(buf);
	buf = temp;
	return (buf);
}

void	set_start_pos(t_game *game, t_map *map, int i, int j)
{
	if (map->start_pos.x == -1 && map->start_pos.y == -1)
	{
		map->start_pos.x = j;
		map->start_pos.y = i;
	}
	else
	{
		game->my_error = "Map can only contain one N, S, E or W!";
		terminate(game);
	}
}

void	set_map_values(t_map *map)
{
	int	height;
	int	width;
	int	len;

	height = 0;
	width = 0;
	len = 0;
	while (map->map[height])
	{
		len = (int)ft_strlen(map->map[height]);
		if (len > width)
			width = len;
		height++;
	}
	map->map_height = height;
	map->map_width = width;
	printf("Height: %d\n", map->map_height);
	printf("Width: %d\n", map->map_width);
}

char	*create_filled_string(char *line, size_t width, size_t len)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * width + 1);
	ft_strlcpy(temp, line, len);
	len--;
	while (len < width)
	{
		temp[len] = '1';
		len++;
	}
	temp[len] = '\0';
	return (temp);
}

void	fill_map(t_game *game, char **map)
{
	char	*temp;
	size_t	width;
	size_t	len;
	int		i;

	width = game->map->map_width;
	len = 0;
	i = 0;
	ft_replace_char(game->map->map, ' ', '1');
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len < width)
		{
			temp = create_filled_string(map[i], width, len);
			free(map[i]);
			map[i] = temp;
		}
		i++;
	}
}

void	check_mapchars(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& !is_player_char(map[i][j]))
			{
				game->my_error = "Map has undefined chars!";
				terminate(game);
			}
			if (is_player_char(map[i][j]))
				set_start_pos(game, game->map, i , j);		
			j++;
		}
		i++;
	}
}

void	create_map(t_game *game, char *buf)
{
	game->map->map = ft_split(buf, '\n');
	free(buf);
	// print_map(game->map->map);
	set_map_values(game->map);
	fill_map(game, game->map->map);
	// print_map(game->map->map);
	// parse_map(game, game->map->map);
	check_mapchars(game, game->map->map);
	game->map->ff_map = copy_map(game->map->map);
	// write(1, "\n", 1);
	// print_map(game->map->ff_map);
	flood_fill(game, game->map->start_pos.x, game->map->start_pos.y);
	print_map(game->map->ff_map);
}

void	check_map(t_game *game, int fd)
{
	char		*line;
	char		*buf;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!game->map->in_map && is_empty_line(line))
		{
			free(line);
			continue ;
		}
		if (is_map(game, line))
			buf = load_map(game, line);
		else
		{
			game->my_error = "Invalid file content!";
			free(buf);
			terminate(game);
		}
	}
	create_map(game, buf);
}
