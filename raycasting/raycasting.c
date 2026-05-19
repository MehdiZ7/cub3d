/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:58:47 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/09 17:11:41 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_game *game)
{
	game->render.hit = false;
	game->render.camera_x = 2 * game->render.x / 800.0 - 1;
	game->render.ray_dir_x = game->player.dir_x + game->player.cam_x
		* game->render.camera_x;
	game->render.ray_dir_y = game->player.dir_y + game->player.cam_y
		* game->render.camera_x;
	game->render.map_x = (int)game->player.pos_x;
	game->render.map_y = (int)game->player.pos_y;
	if (game->render.ray_dir_x == 0)
		game->render.deltadist_x = 1e30;
	else
		game->render.deltadist_x = fabs(1 / game->render.ray_dir_x);
	if (game->render.ray_dir_y == 0)
		game->render.deltadist_y = 1e30;
	else
		game->render.deltadist_y = fabs(1 / game->render.ray_dir_y);
}

void	calcul_step(t_game *game)
{
	if (game->render.ray_dir_x < 0)
	{
		game->render.step_x = -1;
		game->render.sidedist_x = (game->player.pos_x
				- game->render.map_x) * game->render.deltadist_x;
	}
	else
	{
		game->render.step_x = 1;
		game->render.sidedist_x = (game->render.map_x + 1.0
				- game->player.pos_x) * game->render.deltadist_x;
	}
	if (game->render.ray_dir_y < 0)
	{
		game->render.step_y = -1;
		game->render.sidedist_y = (game->player.pos_y
				- game->render.map_y) * game->render.deltadist_y;
	}
	else
	{
		game->render.step_y = 1;
		game->render.sidedist_y = (game->render.map_y + 1.0
				- game->player.pos_y) * game->render.deltadist_y;
	}
}

void	check_hit(t_game *game)
{
	while (game->render.hit == false)
	{
		if (game->render.sidedist_x < game->render.sidedist_y)
		{
			game->render.sidedist_x += game->render.deltadist_x;
			game->render.map_x += game->render.step_x;
			game->render.side = 0;
		}
		else
		{
			game->render.sidedist_y += game->render.deltadist_y;
			game->render.map_y += game->render.step_y;
			game->render.side = 1;
		}
		if (game->map->map[game->render.map_y][game->render.map_x] != '0')
			game->render.hit = true;
	}
}

void	calcul_lines(t_game *game)
{
	if (game->render.side == 0)
		game->render.perpwalldist = game->render.sidedist_x
			- game->render.deltadist_x;
	else
		game->render.perpwalldist = game->render.sidedist_y
			- game->render.deltadist_y;
	game->render.lineheight = (int)(HEIGHT / game->render.perpwalldist);
	game->render.drawstart = -game->render.lineheight / 2 + HEIGHT / 2;
	if (game->render.drawstart < 0)
		game->render.drawstart = 0;
	game->render.drawend = game->render.lineheight / 2 + HEIGHT / 2;
	if (game->render.drawend >= HEIGHT)
		game->render.drawend = HEIGHT - 1;
}

void	render_maths(t_game *game)
{
	game->render.x = 0;
	while (game->render.x < WIDTH)
	{
		init_ray(game);
		calcul_step(game);
		check_hit(game);
		calcul_lines(game);
		get_texture(game);
		calcul_texture(game);
		draw_vertical_line(game, game->render.x);
		game->render.x++;
	}
	render_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.img_ptr, 0, 0);
}
