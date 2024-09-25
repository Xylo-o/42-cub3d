/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:53:39 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/25 15:10:49 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	errno = 0;
	game = (t_game *)malloc(sizeof (t_game));
	if (init(game) == 1)
		return (1);
	check_input(game, argc, argv);
	parser(game, argv);
	mlx_loop_hook(game->mlx, &key_binds, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	if (game->map->map)
		free_array(game->map->map);
	if (game->map->ff_map)
		free_array(game->map->ff_map);
	free_textures(game);
	free_game(game);
	free(game);
	return (0);
}
