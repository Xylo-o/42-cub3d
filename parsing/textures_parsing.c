/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:56:35 by cpuiu             #+#    #+#             */
/*   Updated: 2024/07/13 17:59:00 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*check_tex_get_path(t_game *data, int i, const char *tex_type)
{
	char	*path;

	if (check_valid_texture(data, i, tex_type) == 0)
	{
		path = remove_nl(ft_strnstr(data->file_content[i], "teztures", ft_strlen(data->file_content[i])));
		if (path == NULL)
		{
			printf("Error, invalid path for %s texture.\n", tex_type);
			exit(EXIT_FAILURE);
		}
		return (path);
	}
	return (NULL);
}

void	save_texture(t_game *data, int i)
{
	char	*path;

	path = check_tex_get_path(data, i, "NO");  
	if (path != NULL)
	{
		data->paths.no_path = path;
		return ;
	}
	path = check_tex_get_path(data, i, "SO");
	if (path != NULL)
	{
		data->paths.so_path = path;
		return ;
	}
	path = check_tex_get_path(data, i, "EA");
	if (path != NULL)
	{
		data->paths.ea_path = path;
		return ;
	}
	path = check_tex_get_path(data, i, "WE");
	if (path != NULL)
	{
		data->paths.we_path = path;
		return ;
	}
	if (ft_strchr(data->file_content[i], 'F'))
		data->textures.floor_hex = rgb_to_hex(parse_rgb_str(data->file_content[i]));
	else if (ft_strchr(data->file_content[i], 'C'))
		data->textures.ceiling_hex = rgb_to_hex(parse_rgb_str(data->file_content[i]));
}

int parse_textures_paths(t_game *data, int length)
{
	int i;

	i = 0;
	while (data->file_content[i] != NULL && i < length)
	{
		save_texture(data, i);
		i++;
	}
	if (check_color_path(data) == 0)
		return (0);
	printf("Error,invalid paths or color values.\n");
	exit(1);
}

void	load_and_initialize_textures(mlx_t *mlx, t_game *data)
{
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;

	no_texture = mlx_load_png(data->paths.no_path);
	so_texture = mlx_load_png(data->paths.so_path);
	ea_texture = mlx_load_png(data->paths.ea_path);
	we_texture = mlx_load_png(data->paths.we_path);
	if (!no_texture || !so_texture || !we_texture || !ea_texture)
	{
		printf("Wasn't able to initialize the textures\n");
		exit(EXIT_FAILURE);
	}
	data->textures.no_texture = mlx_texture_to_image(mlx, no_texture);
	data->textures.so_texture = mlx_texture_to_image(mlx, so_texture);
	data->textures.ea_texture = mlx_texture_to_image(mlx, ea_texture);
	data->textures.we_texture = mlx_texture_to_image(mlx, we_texture);
	mlx_delete_texture(no_texture);
	mlx_delete_texture(so_texture);
	mlx_delete_texture(ea_texture);
	mlx_delete_texture(we_texture);
}