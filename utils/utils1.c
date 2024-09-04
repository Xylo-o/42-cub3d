/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:28:35 by adprzyby          #+#    #+#             */
/*   Updated: 2024/08/02 12:26:30 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double ft_factorial(double n)
{
	if (n == 0)
		return (1);
	else
		return (n * ft_factorial(n - 1));
}

double	ft_power(double n, double x)
{
	int		i;
	int		exponent;
	double	result;

	if (x == 0)
		return (1);
	if (n == 0)
		return (0);
	i = 0;
	exponent = (int)x;
	result = 1.0;
	if (x < 0)
	{
		n = 1 / n;
		exponent = exponent * -1;
	}
	while (i < exponent)
	{
		result *= n;
		i++;
	}
	return (result);
}

double	ft_cos(double n)
{
	double	sum;
	int		i;

	i = 0;
	sum = 0;
	while (i < 10)
	{
		sum += ft_power(-1, i) * ft_power(n, 2 * i) / ft_factorial(2 * i);
		i++;
	}
	return (sum);
}

double	ft_sin(double n)
{
	double	sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < 10)
	{
		sum += ft_power(-1, i) * ft_power(n, 2 * i + 1) / ft_factorial(2 * i
				+ 1);
		i++;
	}
	return (sum);
}

double	ft_abs(double n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}
