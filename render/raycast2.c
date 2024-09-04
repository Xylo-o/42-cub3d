/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:35:20 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/30 15:34:56 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

extern int 		worldMap[][mapHeight];

void	calculate_cam(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)screen_w - 1;
	game->ray->dir_x = game->view->dir_x + game->view->cam_x * camera_x;
	game->ray->dir_y = game->view->dir_y + game->view->cam_y * camera_x;
	game->map->map_x = (int)game->view->pos_x;
	game->map->map_y = (int)game->view->pos_y;
}

void	calculate_delta(t_game *game)
{
	if (game->ray->dir_x == 0)
		game->ray->delta_dist_x = 1e30;
	else
		game->ray->delta_dist_x = ft_abs(1 / game->ray->dir_x);
	if (game->ray->dir_y == 0)
		game->ray->delta_dist_y = 1e30;
	else
		game->ray->delta_dist_y = ft_abs(1 / game->ray->dir_y);
}

void	calculate_pos(t_game *game)
{
	if (game->ray->dir_x < 0)
	{
		game->view->step_x = -1;
		game->ray->side_dist_x = (game->view->pos_x - game->map->map_x) * game->ray->delta_dist_x;
	}
	else
	{
		game->view->step_x = 1;
		game->ray->side_dist_x = (game->map->map_x + 1.0 - game->view->pos_x) * game->ray->delta_dist_x;
	}
	if (game->ray->dir_y < 0)
	{
		game->view->step_y = -1;
		game->ray->side_dist_y = (game->view->pos_y - game->map->map_y) * game->ray->delta_dist_y;
	}
	else
	{
		game->view->step_y = 1;
		game->ray->side_dist_y = (game->map->map_y + 1.0 - game->view->pos_y) * game->ray->delta_dist_y;
	}
}

void	calculate_hit(t_game *game)
{
	while (game->map->hit == 0)
	{
		if (game->ray->side_dist_x < game->ray->side_dist_y)
		{
			game->ray->side_dist_x += game->ray->delta_dist_x;
			game->map->map_x += game->view->step_x;
			game->map->side = 0;
		}
		else
		{
			game->ray->side_dist_y += game->ray->delta_dist_y;
			game->map->map_y += game->view->step_y;
			game->map->side = 1;
		}
		if (worldMap[game->map->map_x][game->map->map_y] > 0)
			game->map->hit = 1;
	}
}

void	calculate_ray(t_game *game)
{
	if (game->map->side == 0)
		game->ray->dist = (game->ray->side_dist_x - game->ray->delta_dist_x);
	else
		game->ray->dist = (game->ray->side_dist_y - game->ray->delta_dist_y);
}
