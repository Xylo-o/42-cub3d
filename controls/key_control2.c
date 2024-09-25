/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:51:24 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/25 15:07:47 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

extern int	worldMap[][mapHeight];

void	case_esc(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(game->mlx);
		exit(0);
	}
}

void	case_key_back(t_game *game, double mv_speed)
{
	if (worldMap[(int)(game->view->pos_x - game->view->dir_x
			* mv_speed)][(int)game->view->pos_y] == false)
		game->view->pos_x -= game->view->dir_x * mv_speed;
	if (worldMap[(int)game->view->pos_x][(int)(game->view->pos_y
		- game->view->dir_y * mv_speed)] == false)
		game->view->pos_y -= game->view->dir_y * mv_speed;
}

void	case_key_forward(t_game *game, double mv_speed)
{
	if (worldMap[(int)(game->view->pos_x + game->view->dir_x
			* mv_speed)][(int)game->view->pos_y] == 0)
		game->view->pos_x += game->view->dir_x * mv_speed;
	if (worldMap[(int)game->view->pos_x][(int)(game->view->pos_y
		+ game->view->dir_y * mv_speed)] == 0)
		game->view->pos_y += game->view->dir_y * mv_speed;
}

void	case_key_right(t_game *game, double mv_speed)
{
	if (worldMap[(int)(game->view->pos_x - game->view->dir_y
			* mv_speed)][(int)game->view->pos_y] == 0)
		game->view->pos_x -= game->view->dir_y * mv_speed;
	if (worldMap[(int)game->view->pos_x][(int)(game->view->pos_y
		+ game->view->dir_x * mv_speed)] == 0)
		game->view->pos_y += game->view->dir_x * mv_speed;
}

void	case_key_left(t_game *game, double mv_speed)
{
	if (worldMap[(int)(game->view->pos_x + game->view->dir_y
			* mv_speed)][(int)game->view->pos_y] == 0)
		game->view->pos_x += game->view->dir_y * mv_speed;
	if (worldMap[(int)game->view->pos_x][(int)(game->view->pos_y
		- game->view->dir_x * mv_speed)] == 0)
		game->view->pos_y -= game->view->dir_x * mv_speed;
}
