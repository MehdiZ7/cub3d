/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:38:58 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/09 13:24:30 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_collision(t_game *game, double x, double y)
{
	double	i;

	i = 0.2;
	if (game->map->map[(int)(y + i)][(int)(x + i)] != '0')
		return (false);
	if (game->map->map[(int)(y - i)][(int)(x + i)] != '0')
		return (false);
	if (game->map->map[(int)(y + i)][(int)(x - i)] != '0')
		return (false);
	if (game->map->map[(int)(y - i)][(int)(x - i)] != '0')
		return (false);
	return (true);
}

void	move_forback(int keysym, t_game *game)
{
	double	next_x;
	double	next_y;
	int		sign;

	if (keysym == XK_w)
		sign = 1;
	else
		sign = -1;
	next_x = game->player.pos_x + (game->player.dir_x * SPEED * sign);
	if (check_collision(game, next_x, game->player.pos_y))
		game->player.pos_x = next_x;
	next_y = game->player.pos_y + (game->player.dir_y * SPEED * sign);
	if (check_collision(game, game->player.pos_x, next_y))
		game->player.pos_y = next_y;
}

void	move_rightleft(int keysym, t_game *game)
{
	double	next_x;
	double	next_y;
	int		sign;

	if (keysym == XK_a)
		sign = -1;
	else
		sign = 1;
	next_x = game->player.pos_x + (-game->player.dir_y * SPEED * sign);
	if (check_collision(game, next_x, game->player.pos_y))
		game->player.pos_x = next_x;
	next_y = game->player.pos_y + (game->player.dir_x * SPEED * sign);
	if (check_collision(game, game->player.pos_x, next_y))
		game->player.pos_y = next_y;
}

void	look_right(t_game *game)
{
	double	old_dir;
	double	old_cam;

	old_dir = game->player.dir_x;
	game->player.dir_x = old_dir * cos(TURNSPEED)
		- game->player.dir_y * sin(TURNSPEED);
	game->player.dir_y = old_dir * sin(TURNSPEED)
		+ game->player.dir_y * cos(TURNSPEED);
	old_cam = game->player.cam_x;
	game->player.cam_x = old_cam * cos(TURNSPEED)
		- game->player.cam_y * sin(TURNSPEED);
	game->player.cam_y = old_cam * sin(TURNSPEED)
		+ game->player.cam_y * cos(TURNSPEED);
}

void	look_left(t_game *game)
{
	double	old_dir;
	double	old_cam;

	old_dir = game->player.dir_x;
	game->player.dir_x = old_dir * cos(-TURNSPEED)
		- game->player.dir_y * sin(-TURNSPEED);
	game->player.dir_y = old_dir * sin(-TURNSPEED)
		+ game->player.dir_y * cos(-TURNSPEED);
	old_cam = game->player.cam_x;
	game->player.cam_x = old_cam * cos(-TURNSPEED)
		- game->player.cam_y * sin(-TURNSPEED);
	game->player.cam_y = old_cam * sin(-TURNSPEED)
		+ game->player.cam_y * cos(-TURNSPEED);
}
