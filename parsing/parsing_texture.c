/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:28:13 by sgeiger           #+#    #+#             */
/*   Updated: 2024/09/09 18:43:14 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	count_space(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

bool	is_texture(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
	{
		return (true);
	}
	else
		return (false);
}

void	create_texture(char *path, mlx_texture_t **texture)
{
	if (!*texture)
		*texture = mlx_load_png(path);
	free(path);
	return ;
}

void	check_textures(t_game *game, char *line)
{
	int		fd;
	int		space;
	size_t	len;
	char	*path;

	len = ft_strlen(line);
	if (len < 4)
		return ;
	space = count_space(line + 2);
	path = ft_substr(line, space + 2, len - space - 2);
	printf("-%s-", path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	if (line[0] == 'N')
		create_texture(path, &game->textures->no_texture);
	else if (line[0] == 'S')
		create_texture(path, &game->textures->so_texture);
	else if (line[0] == 'E')
		create_texture(path, &game->textures->ea_texture);
	else if (line[0] == 'W')
		create_texture(path, &game->textures->we_texture);
}
