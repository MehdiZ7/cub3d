/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:25:45 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/14 11:45:28 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_pixel_put(game, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			my_pixel_put(game, x + j, y + i, MAP_PLAYER);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->map_height)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] == '1')
				draw_tile(game, x * TILE_SIZE + MAP_OFFSET,
					y * TILE_SIZE + MAP_OFFSET, MAP_WALL);
			else if (game->map->map[y][x] == '0')
				draw_tile(game, x * TILE_SIZE + MAP_OFFSET,
					y * TILE_SIZE + MAP_OFFSET, MAP_FLOOR);
			else if (game->map->map[y][x] == '2' ||
			game->map->map[y][x] == '3' )
				draw_tile(game, x * TILE_SIZE + MAP_OFFSET,
					y * TILE_SIZE + MAP_OFFSET, MAP_DOOR);
			x++;
		}
		y++;
	}
	draw_player(game, (int)(game->player.pos_x) * TILE_SIZE + MAP_OFFSET,
		(int)(game->player.pos_y) * TILE_SIZE + MAP_OFFSET);
}
