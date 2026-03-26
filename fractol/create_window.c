/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:13:01 by mzouhir           #+#    #+#             */
/*   Updated: 2026/01/05 10:50:00 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	data_init(t_mlx_data *data)
{
	data->escape_value = 4;
	data->iteration = 42;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->zoom = 1.0;
}

int	create_window(t_mlx_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			SIDE_LEN, SIDE_LEN, data->name);
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, SIDE_LEN, SIDE_LEN);
	if (!data->img.img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		clear_window(data);
	}
	data->img.img_pixel_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bit_per_pixel, &data->img.line_len, &data->img.endian);
	data_init(data);
	return (0);
}

void	clear_window(t_mlx_data *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
