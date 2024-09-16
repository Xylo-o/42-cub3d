/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:49:37 by sgeiger           #+#    #+#             */
/*   Updated: 2024/09/16 17:13:22 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i < 10)
			printf(" %d - %s\n", i, map[i]);
		else
			printf("%d - %s\n", i, map[i]);
		i++;
	}
}

void	ft_replace_char(char **line, char c1, char c2)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] == c1)
				line[i][j] = c2;
			j++;
		}
		i++;
	}
}

void	print_line(char *line)
{
	int	i = 0;

	printf("len: %zu line: %s\n", ft_strlen(line), line);
	while (i < 37)
	{
		printf("%d: %c - %d\n", i, line[i], line[i]);
		// write(1,&line[i], 1);
		// printf("-%d\n", line[i]);
		i++;
	}
	write(1, "\n", 1);
}
