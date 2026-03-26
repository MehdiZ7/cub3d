/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:54:48 by mzouhir           #+#    #+#             */
/*   Updated: 2026/01/05 10:56:00 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int				offset;
	unsigned int	*pixel;

	offset = (img->line_len * y) + (x * (img->bit_per_pixel / 8));
	pixel = (unsigned int *)(img->img_pixel_ptr + offset);
	*pixel = (unsigned int)color;
}

// z = z^2 + c
static void	handle_pixel(int x, int y, t_mlx_data *data)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = 0.0;
	z.imaginary = 0.0;
	c.real = scaled_map(x, -2, +2, 799) * data->zoom + data->shift_x;
	c.imaginary = scaled_map(y, +2, -2, 799) * data->zoom + data->shift_y;
	while (i < data->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary)
			> data->escape_value)
		{
			color = scaled_map(i, BLACK, PINK, data->iteration);
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y, BLACK);
}

void	fractal_calcul(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIDE_LEN)
	{
		x = 1;
		while (x < SIDE_LEN)
		{
			handle_pixel(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
