/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:57:46 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/14 14:39:39 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

extern int	worldMap[][mapHeight];

void key_binds(void *param)
{
	t_game *game;
	double mv_speed;
	double rot_speed;

	game = (t_game *)param;
	mv_speed = 0.06;
	rot_speed = 0.05;
	put_image(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		case_key_forward(game, mv_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		case_key_back(game, mv_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		case_key_left(game, mv_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		case_key_right(game, mv_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		case_key_rot_left(game, rot_speed, 0.0, 0.0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		case_key_rot_right(game, rot_speed, 0.0, 0.0);
	case_esc(game);
}
