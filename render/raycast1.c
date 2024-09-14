/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:44:28 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/14 12:30:04 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

extern int 		worldMap[][mapHeight];

#define FLOOR_COLOR 0x00FF00FF
#define	CEILING_COLOR 0X0000FFFF

void	render_structures(t_game *game)
{
	int		wall_height;
	int		draw_start;
	int		draw_end;
	int		x;

	x = 0;
	while (x < screen_w)
	{
		calculate_cam(game, x);
		calculate_delta(game);
		game->map->hit = 0;
		calculate_pos(game);
		calculate_hit(game);
		calculate_ray(game);
		wall_height = (int)(screen_h / game->ray->dist);
		draw_start = calculate_draw_start(wall_height);
		draw_end = calculate_draw_end(wall_height);
		draw_ceiling(game, x, draw_start);
		draw_walls(game, x, draw_start, draw_end, wall_height);
		draw_floor(game, x, draw_end);
		x++;
	}
}

void	put_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->buffer);
	game->buffer = mlx_new_image(game->mlx, screen_w, screen_h);
	render_structures(game);
	mlx_image_to_window(game->mlx, game->buffer, 0, 0);
}

void	draw_walls(t_game *game, int x, int draw_start, int draw_end, int wall_height)
{
	int y;

	y = 0;
    if (game->map->side == 0 && game->ray->dir_x > 0)
		game->textures->tmp = game->textures->no_texture;
    else if (game->map->side == 0 && game->ray->dir_x < 0)
		game->textures->tmp = game->textures->so_texture;
    else if (game->map->side == 1 && game->ray->dir_y > 0)
		game->textures->tmp = game->textures->we_texture;
    else
		game->textures->tmp = game->textures->ea_texture;
    if (game->map->side == 0) game->textures->wall_x = game->view->pos_y + game->ray->dist * game->ray->dir_y;
    else game->textures->wall_x = game->view->pos_x + game->ray->dist * game->ray->dir_x;
    game->textures->wall_x -= floor(game->textures->wall_x);
    game->textures->x_tex = (int)(game->textures->wall_x * (double)tex_width);
    if (game->map->side == 0 && game->ray->dir_x > 0) game->textures->x_tex = tex_width - game->textures->x_tex - 1;
    if (game->map->side == 1 && game->ray->dir_y < 0) game->textures->x_tex = tex_width - game->textures->x_tex - 1;
	y = draw_start;
	while (y < draw_end)
	{
        game->textures->y_tex = (((y * 256 - screen_h * 128 + wall_height * 128) * tex_height) / wall_height) / 256;
		if (game->textures->y_tex >= 0 && game->textures->y_tex < tex_height && game->textures->x_tex >= 0 && game->textures->x_tex < tex_width)
		{
			game->textures->color = (uint32_t*)(game->textures->tmp->pixels + (game->textures->y_tex * tex_width + game->textures->x_tex) * sizeof(uint32_t));
			mlx_put_pixel(game->buffer, x, y, *game->textures->color);
		}
		y++;
    }
}

void	draw_ceiling(t_game *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		mlx_put_pixel(game->buffer, x, y, CEILING_COLOR);
		y++;
	}
}

void	draw_floor(t_game *game, int x, int draw_end)
{
	int	y;

	y = draw_end + 1;
	while (y < screen_h)
	{
		mlx_put_pixel(game->buffer, x, y, FLOOR_COLOR);
		y++;
	}
}
