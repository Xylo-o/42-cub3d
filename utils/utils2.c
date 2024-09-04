/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:17:54 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/04 15:59:32 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

extern int 		worldMap[][mapHeight];

void	get_color(t_game *game, mlx_image_t *texture, int x, int y)
{
	if (worldMap[game->map->map_x][game->map->map_y] == 1)
		game->map->color = 0xFF0000FF; //! red
	else if (worldMap[game->map->map_x][game->map->map_y] == 2)
		game->map->color = 0x00FF00FF; //* green
	else if (worldMap[game->map->map_x][game->map->map_y] == 3)
		game->map->color = 0x0000FFFF; //? blue
	else if (worldMap[game->map->map_x][game->map->map_y] == 4)
		game->map->color = 0xFFFFFFFF; // white
	else
		game->map->color = 0xFFFF00FF; //^ yellow
	game->map->color = texture->pixels[y * texture->width + x];
	if (game->map->side == 1)
	{
		if (game->map->color == 0xFFFFFFFF)
			game->map->color = 0xD3D3D3FF;
		else
			game->map->color = game->map->color / 2;
	}
}

void	get_texture(t_game *game, int x, int y)
{
	int	tex_i;

	tex_i = 0;
	(void)y;
	(void)x;
	if (game->map->side == 1)
	{
		if (game->ray->dir_x > 0)
			get_color(game, game->textures->we_texture, game->x_tex, game->y_tex);
		else
			get_color(game, game->textures->ea_texture, game->x_tex, game->y_tex);
	}
	else if (game->map->side == 0)
	{
		if (game->ray->dir_y > 0)
			get_color(game, game->textures->no_texture, game->x_tex, game->y_tex);
		else
			get_color(game, game->textures->so_texture, game->x_tex, game->y_tex);
	}
	game->y_tex++;
	if (game->y_tex == 64)
		game->y_tex = 0;
}

void	get_color(t_game *game, mlx_texture_t *texture, int x, int y)
{
	if (x < 0 || x >= tex_width || y < 0 || y >= tex_height)
        return;
	game->map->color = ((uint32_t *)texture->pixels)[y * tex_width + x];
}
