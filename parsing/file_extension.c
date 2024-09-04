/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:51:54 by cpuiu             #+#    #+#             */
/*   Updated: 2024/07/13 19:24:38 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int check_file(char *file, char *ext)
{
	char *file_ext;

	file_ext = ft_strrchr(file, '.');
	if (file_ext != NULL)
	{
		if (ft_strncmp(file_ext, ext, ft_strlen(ext) + 1) == 0)
			return (EXIT_SUCCESS);
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}