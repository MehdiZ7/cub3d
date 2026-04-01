/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:18:14 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/01 17:30:51 by mzouhir          ###   ########.fr       */
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

bool	init_textures(t_game *game)
{
	game->textures[0].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, game->map->n_text, &game->textures[0].width,
	&game->textures[0].height);
	if (!game->textures[0].img_ptr)
		return (ft_putstr_fd("Error\n Texture probleme\n", 2), false);
	game->textures[0].img_pixel_ptr = mlx_get_data_addr(game->textures[0].img_ptr
		, &game->textures[0].bit_per_pixel, &game->textures[0].line_len, &game->textures[0].endian);

	game->textures[1].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, game->map->s_text, &game->textures[1].width,
	&game->textures[1].height);
	if (!game->textures[1].img_ptr)
		return (ft_putstr_fd("Error\n Texture probleme\n", 2), false);
	game->textures[1].img_pixel_ptr = mlx_get_data_addr(game->textures[1].img_ptr
		, &game->textures[1].bit_per_pixel, &game->textures[1].line_len, &game->textures[1].endian);

	game->textures[2].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, game->map->e_text, &game->textures[2].width,
	&game->textures[2].height);
	if (!game->textures[2].img_ptr)
		return (ft_putstr_fd("Error\n Texture probleme\n", 2), false);
	game->textures[2].img_pixel_ptr = mlx_get_data_addr(game->textures[2].img_ptr
		, &game->textures[2].bit_per_pixel, &game->textures[2].line_len, &game->textures[2].endian);

	game->textures[3].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, game->map->w_text, &game->textures[3].width,
	&game->textures[3].height);
	if (!game->textures[3].img_ptr)
		return (ft_putstr_fd("Error\n Texture probleme\n", 2), false);
	game->textures[3].img_pixel_ptr = mlx_get_data_addr(game->textures[3].img_ptr
		, &game->textures[3].bit_per_pixel, &game->textures[3].line_len, &game->textures[3].endian);
	return (true);
}

bool	launcher(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (false);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	if (!game->win_ptr)
		return (mlx_destroy_display(game->mlx_ptr), free(game->mlx_ptr), false);
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		return (mlx_destroy_image(game->mlx_ptr, game->img.img_ptr)
			, clear_window(game), false);
	game->img.img_pixel_ptr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bit_per_pixel, &game->img.line_len, &game->img.endian);
	return (true);
}


