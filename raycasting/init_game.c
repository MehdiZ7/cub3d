/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:18:14 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/31 14:48:29 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_window(t_game *game)
{
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

bool	launcher(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (false);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "CUB3D");
	if (!game->win_ptr)
		return (mlx_destroy_display(game->mlx_ptr), free(game->mlx_ptr), false);
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, 800, 600);
	if (!game->img.img_ptr)
		return (mlx_destroy_image(game->mlx_ptr, game->img.img_ptr)
			, clear_window(game), false);
	game->img.img_pixel_ptr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bit_per_pixel, &game->img.line_len, &game->img.endian);
	return (true);
}


