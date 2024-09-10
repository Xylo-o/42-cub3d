/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:28:11 by sgeiger           #+#    #+#             */
/*   Updated: 2024/09/09 19:17:25 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	is_color(char *line)
{
	if ((!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		&& ft_strlen(line) >= 7)
		return (true);
	return (false);
}

void	set_hex_value(t_game *game, int nbr, char c)
{
	static int	i = 0;
	static int	red = -1;
	static int	green = -1;
	static int	blue = -1;

	// printf("Start: C_Hex: 0x%06lX\n", game->textures->ceiling_hex);
	// printf("Start: F_Hex: 0x%06lX\n", game->textures->floor_hex);
	// printf("%d\n", i);
	if (i == 0)
		red = nbr;
	else if (i == 1)
		green = nbr;
	else if (i == 2)
		blue = nbr;
	else
	{
		if (c == 'F')
			game->textures->floor_hex = (red << 16) | (green << 8) | blue;
		else if (c == 'C')
			game->textures->ceiling_hex = (red << 16) | (green << 8) | blue;
		printf("C_Hex: %06lX\n", game->textures->ceiling_hex);
		printf("F_Hex: %06lX\n", game->textures->floor_hex);
	}
	i++;
	// printf("%d\n", i);
}

void	check_color(t_game *game, char *line)
{
	size_t	i;
	size_t	start;
	char	*str_nbr;

	i = 2;
	while (line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		start = i;
		while (ft_isdigit(line[i]))
			i++;
		str_nbr = ft_substr(line, start, i - start);
		printf("%s\n", str_nbr);
		if (ft_strlen(str_nbr) > 3
			|| (ft_strcmp(str_nbr, "255") > 0 && ft_strlen(str_nbr) == 3))
			return ;
		printf("I was here\n");
		set_hex_value(game, ft_atoi(str_nbr), line[0]);
		free (str_nbr);
		while (ft_isspace(line[i]))
			i++;
		if (line[i] && line[i] != ',')
			return ;
		i++;
	}
	set_hex_value(game, 0, line[0]);
}
