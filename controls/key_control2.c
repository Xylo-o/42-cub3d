/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:51:24 by adprzyby          #+#    #+#             */
/*   Updated: 2024/10/03 18:36:29 by adprzyby         ###   ########.fr       */
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
    double next_pos_x = game->view->pos_x - game->view->dir_x * (mv_speed + game->view->buff_dist);
    double next_pos_y = game->view->pos_y - game->view->dir_y * (mv_speed + game->view->buff_dist);

    if (game->map->map[(int)next_pos_x][(int)game->view->pos_y] == '0')
        game->view->pos_x -= game->view->dir_x * mv_speed;
    if (game->map->map[(int)game->view->pos_x][(int)next_pos_y] == '0')
        game->view->pos_y -= game->view->dir_y * mv_speed;
}

void	case_key_forward(t_game *game, double mv_speed)
{
    double next_pos_x = game->view->pos_x + game->view->dir_x * (mv_speed + game->view->buff_dist);
    double next_pos_y = game->view->pos_y + game->view->dir_y * (mv_speed + game->view->buff_dist);

    if (game->map->map[(int)next_pos_x][(int)game->view->pos_y] == '0')
        game->view->pos_x += game->view->dir_x * mv_speed;
    if (game->map->map[(int)game->view->pos_x][(int)next_pos_y] == '0')
        game->view->pos_y += game->view->dir_y * mv_speed;
}

void	case_key_right(t_game *game, double mv_speed)
{
    double next_pos_x = game->view->pos_x + game->view->cam_x * (mv_speed + game->view->buff_dist);
    double next_pos_y = game->view->pos_y + game->view->cam_y * (mv_speed + game->view->buff_dist);

    if (game->map->map[(int)next_pos_x][(int)game->view->pos_y] == '0')
        game->view->pos_x += game->view->cam_x * mv_speed;
    if (game->map->map[(int)game->view->pos_x][(int)next_pos_y] == '0')
        game->view->pos_y += game->view->cam_y * mv_speed;
}

void	case_key_left(t_game *game, double mv_speed)
{
    double next_pos_x = game->view->pos_x - game->view->cam_x * (mv_speed + game->view->buff_dist);
    double next_pos_y = game->view->pos_y - game->view->cam_y * (mv_speed + game->view->buff_dist);

    if (game->map->map[(int)next_pos_x][(int)game->view->pos_y] == '0')
        game->view->pos_x -= game->view->cam_x * mv_speed;
    if (game->map->map[(int)game->view->pos_x][(int)next_pos_y] == '0')
        game->view->pos_y -= game->view->cam_y * mv_speed;
}
