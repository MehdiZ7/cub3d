/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player .c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:38:57 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/31 17:53:23 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
}

void	set_camera(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.cam_x = 0.66;
		game->player.cam_y = 0;
	}
	else if (c == 'S')
	{
		game->player.cam_x = -0.66;
		game->player.cam_y = 0;
	}
	else if (c == 'E')
	{
		game->player.cam_x = 0;
		game->player.cam_y = 0.66;
	}
	else if (c == 'W')
	{
		game->player.cam_x = 0;
		game->player.cam_y = -0.66;
	}
}

void	init_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (is_position(game->map->map[i][j]))
			{
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
				set_direction(game, game->map->map[i][j]);
				set_camera(game, game->map->map[i][j]);
				game->map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
