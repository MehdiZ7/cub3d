/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:52:47 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/13 12:45:54 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	use_door(t_game *game)
{
	int	check_x;
	int	check_y;

	check_x = (int)(game->player.pos_x + game->player.dir_x);
	check_y = (int)(game->player.pos_y + game->player.dir_y);
	if (game->map->map[check_y][check_x] == '2')
		game->map->map[check_y][check_x] = '3';
	else if (game->map->map[check_y][check_x] == '3')
		game->map->map[check_y][check_x] = '2';
}

int	key_handle(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		free_mapinfo(game->map);
		clear_window(game);
		exit(0);
	}
	else if (keysym == XK_w || keysym == XK_s)
		move_forback(keysym, game);
	else if (keysym == XK_d || keysym == XK_a)
		move_rightleft(keysym, game);
	else if (keysym == XK_Right)
		look_right(game);
	else if (keysym == XK_Left)
		look_left(game);
	else if (keysym == XK_space)
		use_door(game);
	render_maths(game);
	return (0);
}

int	cross_handle(t_game *game)
{
	free_mapinfo(game->map);
	clear_window(game);
	exit(0);
}

void	events_init(t_game *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_handle, game);
	mlx_hook(game->win_ptr, DestroyNotify,
		StructureNotifyMask, cross_handle, game);
}
