/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:53:39 by adprzyby          #+#    #+#             */
/*   Updated: 2024/10/10 13:53:52 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void check_for_leaks(void)
// {
//     char command[256];
//     pid_t pid = getpid();
//     sprintf(command, "leaks %d", pid);
//     system(command);
// }

int	main(int argc, char *argv[])
{
	t_game	*game;

	errno = 0;
	game = (t_game *)malloc(sizeof (t_game));
	init(game);
	check_input(game, argc, argv);
	parser(game, argv);
	spawn_player(game);
	mlx_loop_hook(game->mlx, &key_binds, game);
	mlx_loop(game->mlx);

	// check_for_leaks();
	
	mlx_terminate(game->mlx);
	free_up(game);
	return (0);
}
