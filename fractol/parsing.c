/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:36:52 by mzouhir           #+#    #+#             */
/*   Updated: 2026/01/05 11:00:51 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	error_input_julia(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str))
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			if (*str != '.')
				return (1);
			str++;
			break ;
		}
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	check_input(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot\0", 11))
		return (1);
	else if (ac == 2 && !ft_strncmp(av[1], "burning\0", 8))
		return (1);
	else if (ac == 4 && !ft_strncmp(av[1], "julia\0", 6))
	{
		if (!error_input_julia(av[2]) && !error_input_julia(av[3]))
			return (1);
		else
		{
			ft_printf("Invalid command for Julia\n");
			return (0);
		}
	}
	else
	{
		ft_printf("Invalid command\n");
		return (0);
	}
}
