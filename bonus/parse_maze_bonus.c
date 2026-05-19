/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maze_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:20:53 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/13 12:13:30 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_maze_line(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0' || line[i] == '2')
		return (true);
	return (false);
}

bool	create_maze_line(t_mapinfo *t_map, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(t_map->map_line, line);
	if (!tmp)
		return (ft_putstr_fd("Error\n Malloc failure", 2), false);
	free(t_map->map_line);
	t_map->map_line = tmp;
	return (true);
}

bool	init_maze(t_mapinfo *t_map)
{
	int	i;

	i = 0;
	t_map->map = ft_split(t_map->map_line, '\n');
	if (!t_map->map)
		return (ft_putstr_fd("Error\n Malloc failure", 2), false);
	while (t_map->map[i])
		i++;
	t_map->map_height = i;
	if (!check_char_map(t_map))
		return (ft_putstr_fd("Error\n Invalid map character", 2), false);
	if (!validate_map(t_map))
		return (ft_putstr_fd("Error\n Invalid map walls", 2), false);
	return (true);
}
