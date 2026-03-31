/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:44:08 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/31 13:31:36 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_position(t_mapinfo *t_map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (t_map->map[i])
	{
		j = 0;
		while (t_map->map[i][j])
		{
			if (is_position(t_map->map[i][j]))
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**copy_map(t_mapinfo *t_map)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = ft_calloc(t_map->map_height + 1, sizeof(char *));
	if (!cpy)
		return (ft_putstr_fd("Error\n Malloc failure\n", 2), NULL);
	while (i < t_map->map_height)
	{
		cpy[i] = ft_strdup(t_map->map[i]);
		if (!cpy[i])
			return (free_tab(cpy),
				ft_putstr_fd("Error\n Malloc failure\n", 2), NULL);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

bool	floodfill(char **map_cpy, int x, int y, int height)
{
	if (y < 0 || y >= height)
		return (false);
	if (x < 0 || x >= (int)ft_strlen(map_cpy[y]))
		return (false);
	if (map_cpy[y][x] == ' ')
		return (false);
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'X')
		return (true);
	map_cpy[y][x] = 'X';
	if (!floodfill(map_cpy, x, y -1, height)
		|| !floodfill(map_cpy, x, y + 1, height)
		|| !floodfill(map_cpy, x + 1, y, height)
		|| !floodfill(map_cpy, x - 1, y, height))
		return (false);
	return (true);
}

bool	validate_map(t_mapinfo *t_map)
{
	bool	res;
	char	**cpy;
	int		x;
	int		y;

	cpy = copy_map(t_map);
	if (!cpy)
		return (false);
	find_position(t_map, &x, &y);
	res = floodfill(cpy, x, y, t_map->map_height);
	free_tab(cpy);
	return (res);
}
