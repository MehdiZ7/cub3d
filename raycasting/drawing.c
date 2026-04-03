/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:48:22 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/03 15:31:47 by mzouhir          ###   ########.fr       */
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
	int				y;
	double			step;
	double			tex_pos;
	int				offset;
	unsigned int	color;

	step = 1.0 * game->textures[game->render.tex_id].height / game->render.lineheight;
	tex_pos = (game->render.drawstart - HEIGHT / 2.0 + game->render.lineheight / 2.0) * step;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < game->render.drawstart)
			my_pixel_put(game, x, y, game->map->sky_color);
		else if (y >= game->render.drawstart && y <= game->render.drawend)
		{
			game->render.tex_y = (int)tex_pos & (game->textures[game->render.tex_id].height - 1);
			tex_pos += step;
			offset = (game->textures[game->render.tex_id].line_len * game->render.tex_y)
				+ (game->render.tex_x * (game->textures[game->render.tex_id].bit_per_pixel / 8));
			color = *(unsigned int *)(game->textures[game->render.tex_id].img_pixel_ptr + offset);
			my_pixel_put(game, x, y, color);
		}
		else
			my_pixel_put(game, x, y, game->map->floor_color);
		y++;
	}
}
