/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:39:02 by adprzyby             #+#    #+#             */
/*   Updated: 2024/01/09 15:32:54 by adprzyby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_size;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(total_size * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, total_size);
	ft_strlcat(new_str, s2, total_size);
	return (new_str);
}
