/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:52:47 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/09 13:25:18 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
