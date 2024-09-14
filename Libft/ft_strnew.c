/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:24:20 by adprzyby             #+#    #+#             */
/*   Updated: 2024/01/09 15:24:32 by adprzyby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)(ft_memalloc(size + 1));
	if (res == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < size + 1)
		{
			res[i] = '\0';
			i++;
		}
	}
	return (res);
}
