/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:26:08 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/08 12:30:13 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(t_game *game)
{
	if (game->map->map[game->render.map_y][game->render.map_x] == '2')
	{
		game->render.tex_id = 4;
		return ;
	}
	if (game->render.side == 0)
	{
		if (game->render.ray_dir_x > 0)
			game->render.tex_id = 3;
		else
			game->render.tex_id = 2;
	}
	else
	{
		if (game->render.ray_dir_y > 0)
			game->render.tex_id = 0;
		else
			game->render.tex_id = 1;
	}
}

void	calcul_texture(t_game *game)
{
	if (game->render.side == 0)
		game->render.wall_x = game->player.pos_y + game->render.perpwalldist
			* game->render.ray_dir_y;
	else
		game->render.wall_x = game->player.pos_x + game->render.perpwalldist
			* game->render.ray_dir_x;
	game->render.wall_x -= floor(game->render.wall_x);
	game->render.tex_x = (int)(game->render.wall_x
			* (double)game->textures[game->render.tex_id].width);
	if (game->render.side == 0 && game->render.ray_dir_x > 0)
		game->render.tex_x = game->textures[game->render.tex_id].width
			- game->render.tex_x - 1;
	if (game->render.side == 1 && game->render.ray_dir_y < 0)
		game->render.tex_x = game->textures[game->render.tex_id].width
			- game->render.tex_x - 1;
}
