/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:45:07 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/14 12:21:18 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

void	init_view(t_view *view)
{
	if (!view)
		return ;
	view->cam_x = 0;
	view->cam_y = 0.66;
	view->dir_x = 1;
	view->dir_y = 0;
	view->pos_x = 22;
	view->pos_y = 11.5;
	view->step_x = 0;
	view->step_y = 0;
}

void	init_map(t_map *map)
{
	map->map_x = 0;
	map->map_y = 0;
	map->side = 0;
	map->hit = 0;
}

void	init_ray(t_ray *ray)
{
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->dist = 0;
	ray->x_zero = 0;
	ray->x_max = 0;
	ray->y_zero = 0;
	ray->y_max = 0;
}

int	init(t_game *game)
{
	if (!game)
		return (1);
	game->mlx = mlx_init(screen_w, screen_h, "cub3D", false);
	if (!game->mlx)
		return (1);
	game->buffer = mlx_new_image(game->mlx, screen_w, screen_h);
	if (!game->buffer)
		return (1);
	game->view = (t_view *)malloc(sizeof(t_view));
	if (!game->view)
		return (1);
	init_view(game->view);
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
		return (1);
	init_map(game->map);
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!game->ray)
		return (1);
	init_ray(game->ray);
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!game->textures)
		return (1);
	load_textures(game);
	return (0);
}
