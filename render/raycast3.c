/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:18:32 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/16 11:02:46 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

extern int	worldMap[][mapHeight];

int	calculate_draw_end(int wall_height)
{
	int	draw_end;

	draw_end = 0;
	draw_end = wall_height / 2 + SCREEN_H / 2;
	if (draw_end >= SCREEN_H)
		draw_end = SCREEN_H - 1;
	return (draw_end);
}

int	calculate_draw_start(int wall_height)
{
	int	draw_start;

	draw_start = 0;
	draw_start = -wall_height / 2 + SCREEN_H / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
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
