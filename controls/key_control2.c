/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:51:24 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/27 22:42:28 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	case_esc(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

void	case_key_back(t_game *game, double mv_speed)
{
	if (game->map->map[(int)(game->view->pos_x - game->view->dir_x
			* mv_speed)][(int)game->view->pos_y] == '0')
		game->view->pos_x -= game->view->dir_x * mv_speed;
	if (game->map->map[(int)game->view->pos_x][(int)(game->view->pos_y
		- game->view->dir_y * mv_speed)] == '0')
		game->view->pos_y -= game->view->dir_y * mv_speed;
}

void	case_key_forward(t_game *game, double mv_speed)
{
	if (game->map->map[(int)(game->view->pos_x + game->view->dir_x
			* mv_speed)][(int)game->view->pos_y] == '0')
		game->view->pos_x += game->view->dir_x * mv_speed;
	if (game->map->map[(int)game->view->pos_x][(int)(game->view->pos_y
		+ game->view->dir_y * mv_speed)] == '0')
		game->view->pos_y += game->view->dir_y * mv_speed;
}

void	case_key_right(t_game *game, double mv_speed)
{
	if (game->map->map[(int)(game->view->pos_x - game->view->dir_y
			* mv_speed)][(int)game->view->pos_y] == '0')
		game->view->pos_x -= game->view->dir_y * mv_speed;
	if (game->map->map[(int)game->view->pos_x][(int)(game->view->pos_y
		+ game->view->dir_x * mv_speed)] == '0')
		game->view->pos_y += game->view->dir_x * mv_speed;
}

void	case_key_left(t_game *game, double mv_speed)
{
	if (game->map->map[(int)(game->view->pos_x + game->view->dir_y
			* mv_speed)][(int)game->view->pos_y] == '0')
		game->view->pos_x += game->view->dir_y * mv_speed;
	if (game->map->map[(int)game->view->pos_x][(int)(game->view->pos_y
		- game->view->dir_x * mv_speed)] == '0')
		game->view->pos_y -= game->view->dir_x * mv_speed;
}
