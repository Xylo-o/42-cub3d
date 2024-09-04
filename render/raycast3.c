/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:18:32 by adprzyby          #+#    #+#             */
/*   Updated: 2024/08/06 16:53:47 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

int	calculate_draw_end(int wall_height)
{
	int draw_end;

	draw_end = 0;
	draw_end = wall_height / 2 + screen_h / 2;
	if (draw_end >= screen_h)
		draw_end = screen_h - 1;
	return (draw_end);
}

int	calculate_draw_start(int wall_height)
{
	int draw_start;
	
	draw_start = 0;
	draw_start = -wall_height / 2 + screen_h / 2;
	if (draw_start < 0)
		draw_start = 0;
	return(draw_start);
}
