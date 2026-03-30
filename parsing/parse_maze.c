/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:20:53 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/30 17:46:43 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_maze_line(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (true);
	return (false);
}

bool	create_maze_line(t_mapinfo *t_map, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(t_map->map_line, line);
	if (!tmp)
		return (ft_putstr_fd("Error: Malloc failure", 2), false);
	free(t_map->map_line);
	t_map->map_line = tmp;
	return (true);
}
