/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:52:47 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/31 16:01:06 by mzouhir          ###   ########.fr       */
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
