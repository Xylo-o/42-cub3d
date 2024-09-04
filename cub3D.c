/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:53:39 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/04 15:43:17 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int	main(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof (t_game));
	if (init(game) == 1)
		return (1);
	// generate_textures();
	mlx_loop_hook(game->mlx, &key_binds, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
