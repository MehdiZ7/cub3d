/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:36:16 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/09 14:19:32 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	game_laucher(t_game *game)
{
	if (!launcher(game))
		return (free_mapinfo(game->map)
			, ft_putstr_fd("Error\n Initialisation window failure\n", 2), 1);
	if (!init_textures(game))
		return (clear_window(game), free_mapinfo(game->map), 1);
	events_init(game);
	init_player_pos(game);
	render_maths(game);
	mlx_loop(game->mlx_ptr);
	free_mapinfo(game->map);
	return (0);
}

int	main(int ac, char **av)
{
	int			fd;
	t_game		game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		return (ft_putstr_fd("Error\n Wrong number of argument\n", 2), 1);
	if (!check_extension(av[1]))
		return (ft_putstr_fd("Error\n Not a .cub map\n", 2), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\n Impossible to open map\n", 2), 1);
	game.map = parse_map(fd);
	if (!game.map)
		return (1);
	return (game_laucher(&game));
}
