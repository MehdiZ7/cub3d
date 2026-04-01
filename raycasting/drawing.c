/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:48:22 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/01 14:34:46 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_game *game, int x, int y, int color)
{
	int				offset;
	unsigned int	*pixel;

	offset = (game->img.line_len * y) + (x * (game->img.bit_per_pixel / 8));
	pixel = (unsigned int *)(game->img.img_pixel_ptr + offset);
	*pixel = (unsigned int)color;
}

void	draw_vertical_line(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < game->render.drawstart)
			my_pixel_put(game, x, y, game->map->sky_color);
		else if (y >= game->render.drawstart && y <= game->render.drawend)
		{
			if (game->render.side == 1)
				my_pixel_put(game, x, y, 0xFF0000);
			else
				my_pixel_put(game, x, y, 0x880000);

		}
		else
			my_pixel_put(game, x, y, game->map->floor_color);
		y++;
	}
}
