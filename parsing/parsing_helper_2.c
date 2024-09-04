#include "../cub3D.h"

void valid_texture_line(char *str, char *type)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (ft_strncmp(&str[i], type, ft_strlen(type)) == 0)
		{
			i += 2;
			break;
		}
		else if (str[i] != ' ' && str[i] != '\t')
			exit(1);
		i++;
	}
	while (str[i])
	{
		if (ft_strncmp(&str[i], "textures", ft_strlen("textures")) == 0
			|| ft_strncmp(&str[i], "./textures", ft_strlen("./textures")) == 0
			|| ft_strncmp(&str[i], ".textures", ft_strlen(".textures")) == 0)
			return ;
		else if (str[i] != ' ' && str[i] != '\t')
			exit(1);
		i++;
	}
}

void check_valid_path(t_game *game, int y, int x)
{
	if (game->tmp[y][x] == 'V' || game->tmp[y][x] == '1')
		return ;
	if (valid_cell_path(game, y, x))
	{
		printf("Map path isn't valid\n");
		exit(1);
	}
	else if (game->tmp[y][x] == game->player.direction || game->tmp[y][x] == '0')
	{
		game->tmp[y][x] = 'V';
		check_valid_path(game, y, x + 1);
		if (x > 0)
			check_valid_path(game, y, x - 1);
		if (game->tmp[y + 1] != NULL)
			check_valid_path(game, y + 1, x);
		if (y > 0)
			check_valid_path(game, y - 1, x);
	}
}


int valid_cell_path(t_game *game, int y, int x)
{
	char pos;
	size_t length;

	pos = game->player.direction;
	length = line_length(game->tmp[y], &game->tmp[y][x]);
	if (y > 0 && length > (ft_strlen(game->tmp[y - 1]) - 1))
		return (1);
	else if (game->tmp[y + 1] && length > (ft_strlen(game->tmp[y + 1]) - beflastline(game->tmp, y)))
		return (1);
	if (game->tmp[y][x] == ' ' || ((game->tmp[y][x] == '0' || game->tmp[y][x] == pos) && y == 0) 
		|| ((game->tmp[y][x] == '0' || game->tmp[y][x] == pos) && game->tmp[y + 1] == NULL) 
		|| ((game->tmp[y][x] == '0' || game->tmp[y][x] == pos) && x == 0) 
		|| ((game->tmp[y][x] == '0' || game->tmp[y][x] == pos) && (game->tmp[y][x + 1] == '\n' || game->tmp[y][x + 1] == '\0')))
	{
		return (1);
	}
	return (0);
}

size_t line_length(char *line, char *start)
{
	size_t length;

	length = 0;
	while (line != start)
	{
		line++;
		length++;
	}
	return (length);
}

int beflastline(char **map, int y)
{
	int i;

	i = 0;
	while (map[y][i])
		i++;
	return (i);
}

size_t get_index(char *line, char *type)
{
	size_t i;

	i = 0;
	while (*line && line != type)
	{
		line++;
		i++;
	}
	return (i);
}