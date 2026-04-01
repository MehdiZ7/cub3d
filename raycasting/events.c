/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:52:47 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/01 16:13:32 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handle(int keysym, t_game *game)
{
	double	next_move;

	if (keysym == XK_Escape)
	{
		free_mapinfo(game->map);
		clear_window(game);
		exit(0);
	}
	else if (keysym == XK_w)
	{
		next_move = game->player.pos_x + (game->player.dir_x * SPEED);
		if (game->map->map[(int)game->player.pos_y][(int)next_move] == '0')
		game->player.pos_x = next_move;
		next_move = game->player.pos_y + (game->player.dir_y * SPEED);
		if (game->map->map[(int)next_move][(int)game->player.pos_x] == '0')
		game->player.pos_y = next_move;
	}
	else if (keysym == XK_s)
	{
		next_move = game->player.pos_x - (game->player.dir_x * SPEED);
		if (game->map->map[(int)game->player.pos_y][(int)next_move] == '0')
		game->player.pos_x = next_move;
		next_move = game->player.pos_y - (game->player.dir_y * SPEED);
		if (game->map->map[(int)next_move][(int)game->player.pos_x] == '0')
		game->player.pos_y = next_move;
	}
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
