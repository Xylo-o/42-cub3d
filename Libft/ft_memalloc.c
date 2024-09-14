/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:27:00 by adprzyby             #+#    #+#             */
/*   Updated: 2024/01/09 15:27:13 by adprzyby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < size)
		{
			*(char *)(res + i) = 0;
			i++;
		}
		return (res);
	}
}
