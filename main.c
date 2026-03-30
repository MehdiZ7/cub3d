/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:36:16 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/28 16:50:57 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int			fd;
	t_mapinfo	*t_map;

	if (ac != 2)
		return (ft_putstr_fd("Error: Wrong number of argument\n", 2), 1);
	if (!check_extension(av[1]))
		return (ft_putstr_fd("Error: Not a .cub map\n", 2), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error: Impossible to open map\n", 2), 1);
	t_map = parse_map(fd);
}
