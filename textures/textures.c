/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:50:29 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/23 17:02:03 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// void    load_textures(t_game *game)
// {
// 	// int	i;

// 	// i = 0;
// 	// while (i < 4)
// 	// {
// 	// 	game->textures->pixar[i] = malloc(sizeof(int) * 64 * 64);
// 	// 	if (!game->textures->pixar[i])
// 	// 	{
// 	// 		printf("Failed to initialize texture buffer\n");
// 	// 		exit(1);
// 	// 	}
// 	// 	i++;
// 	// }
// 	game->textures->no_texture = mlx_load_png(game->paths->no_path);
//     game->textures->so_texture = mlx_load_png(game->paths->so_path);
//     game->textures->we_texture = mlx_load_png(game->paths->we_path);
//     game->textures->ea_texture = mlx_load_png(game->paths->ea_path);
// 	game->textures->tmp = NULL;
//     if (!game->textures->no_texture || !game->textures->so_texture 
// 	|| !game->textures->we_texture || !game->textures->ea_texture)
//     {
//         printf("Wasn't able to initialize the textures\n");
//         exit(EXIT_FAILURE);
//     }
// 	game->textures->pixar = 0;
// }
