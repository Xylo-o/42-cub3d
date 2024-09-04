/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convertor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:08:08 by cpuiu             #+#    #+#             */
/*   Updated: 2024/07/15 18:13:07 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

long	rgb_to_hex(char *line)
{
	check_comma(line);
	return (return_hex_rgb(line));
}

void	check_comma(char *line)
{
	int i;
	int comma_count;

	i = 0;
	comma_count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
	{
		printf("Error, invalid color format.\n");
		exit(EXIT_FAILURE);
	}
}

long	return_hex_rgb(char *line)
{
	int		r;
	int		g;
	int		b;
	long	hex;

	r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	b = ft_atoi(line);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error, invalid color format.\n");
		exit(EXIT_FAILURE);
	}
	hex = (r << 16) + (g << 8) + b;
	return (hex);
}