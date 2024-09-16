/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:53:39 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/16 11:00:06 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	game->textures->no_texture = mlx_load_png("textures/pics/bluestone.png");
	game->textures->so_texture = mlx_load_png("textures/pics/colorstone.png");
	game->textures->we_texture = mlx_load_png("textures/pics/greystone.png");
	game->textures->ea_texture = mlx_load_png("textures/pics/redbrick.png");
	game->textures->wall_x = 0;
	game->textures->color = 0;
	game->textures->x_tex = 0;
	game->textures->y_tex = 0;
	if (!game->textures->no_texture || !game->textures->so_texture
		|| !game->textures->we_texture || !game->textures->ea_texture)
	{
		printf("Error loading texture %d\n", i);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (init(game) == 1)
		return (1);
	mlx_loop_hook(game->mlx, &key_binds, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
