/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:57:46 by adprzyby          #+#    #+#             */
/*   Updated: 2024/08/02 09:51:01 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

extern int	worldMap[][mapHeight];

void	key_binds(void *param)
{
	t_game	*game;
	double	old_dir_x;
	double	old_cam_x;
	double	mv_speed;
	double	rot_speed;

	game = (t_game *)param;
	old_dir_x = 0.0;
	old_cam_x = 0.0;
	mv_speed = 0.1;
	rot_speed = 0.05;
	put_image(game);
	case_key_up(game, mv_speed);
	case_key_down(game, mv_speed);
	case_key_left(game, rot_speed, old_dir_x, old_cam_x);
	case_key_right(game, rot_speed, old_dir_x, old_cam_x);
	case_esc(game);
}
