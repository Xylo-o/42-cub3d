/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:52:08 by sgeiger           #+#    #+#             */
/*   Updated: 2024/09/22 01:19:54 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// static void	free_textures(t_game *game)
// {
// 	if (game->textures->no_texture)
// 		mlx_delete_texture(game->textures->no_texture);
// 	if (game->textures->so_texture)
// 		mlx_delete_texture(game->textures->so_texture);
// 	if (game->textures->ea_texture)
// 		mlx_delete_texture(game->textures->ea_texture);
// 	if (game->textures->we_texture)
// 		mlx_delete_texture(game->textures->we_texture);
// 	if (game->mlx)
// 		mlx_terminate(game->mlx);
// }

void	free_game(t_game *game)
{
	if (game->view)
		free(game->view);
	if (game->map)
		free(game->map);
	if (game->ray)
		free(game->ray);
	if (game->paths)
		free(game->paths);
	if (game->textures)
		free(game->textures);
}

static void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// void	ft_mlx_error(void)
// {
// 	size_t		len;
// 	const char	*str;

// 	str = mlx_strerror(mlx_errno);
// 	len = ft_strlen(str);
// 	write(STDOUT_FILENO, &str, len);
// }

void	terminate(t_game *game)
{
	if (game->map->map)
		free_array(game->map->map);
	if (game->map->ff_map)
		free_array(game->map->ff_map);
	// free_textures(game);
	free_game(game);
	if (game->my_error != NULL)
	{
		write(STDERR_FILENO, "Error: ", 7);
		write(STDERR_FILENO, game->my_error, ft_strlen(game->my_error));
		write(STDERR_FILENO, "\n", 1);
	}
	// else if (mlx_errno != 0)
	// 	ft_mlx_error();
	else if (errno != 0)
		perror("Error");
	free(game);
	exit(EXIT_FAILURE);
}
