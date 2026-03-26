/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:36:27 by mzouhir           #+#    #+#             */
/*   Updated: 2026/01/05 10:59:16 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (!check_input(ac, av))
		exit(1);
	data.name = av[1];
	if (create_window(&data))
		return (1);
	if (!ft_strncmp(data.name, "mandelbrot", 10))
		fractal_calcul(&data);
	else if (!ft_strncmp(data.name, "julia", 5))
	{
		data.julia_x = ft_atod(av[2]);
		data.julia_y = ft_atod(av[3]);
		fractal_calcul_julia(&data);
	}
	else if (!ft_strncmp(data.name, "burning", 7))
		fractal_calcul_burning(&data);
	events_init(&data);
	mlx_loop(data.mlx_ptr);
	clear_window(&data);
	return (0);
}
