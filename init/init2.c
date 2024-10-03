/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:04:42 by adprzyby          #+#    #+#             */
/*   Updated: 2024/10/04 01:49:48 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	spawn_player(t_game *game)
{
	if (game->map->start_orientation == 'W')
	{
		game->view->dir_x = 0;
		game->view->dir_y = -1;
		game->view->cam_x = 0.66;
		game->view->cam_y = 0;
	}
	else if (game->map->start_orientation == 'E')
	{
		game->view->dir_x = 0;
		game->view->dir_y = 1;
		game->view->cam_x = -0.66;
		game->view->cam_y = 0;
	}
	else if (game->map->start_orientation == 'N')
	{
		game->view->dir_x = 1;
		game->view->dir_y = 0;
		game->view->cam_x = 0;
		game->view->cam_y = 0.66;
	}
	else if (game->map->start_orientation == 'S')
	{
		game->view->dir_x = -1;
		game->view->dir_y = 0;
		game->view->cam_x = 0;
		game->view->cam_y = -0.66;
	}
	game->view->pos_x = game->map->start_pos.x + 0.5;
	game->view->pos_y = game->map->start_pos.y + 0.5;
}
