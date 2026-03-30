/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:08:37 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/30 18:09:16 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (false);
	i -= 4;
	if (!ft_strncmp(&str[i], ".cub", 5))
		return (true);
	return (false);
}

bool	extract_path(char **map_path, char *line)
{
	char	*path;

	if (*map_path != NULL)
		return (ft_putstr_fd("Error: Same texture existing\n", 2), false);
	path = ft_strtrim(line, " \n\t");
	if (!path)
		return (ft_putstr_fd("Error: Malloc failure\n", 2), false);
	*map_path = path;
	return (true);
}

bool	check_type(t_mapinfo *t_map, char *line, int i)
{
	if (!ft_strncmp(&line[i], "NO ", 3))
		return (extract_path(&(t_map->n_text), &line[i + 3]));
	else if (!ft_strncmp(&line[i], "SO ", 3))
		return (extract_path(&(t_map->s_text), &line[i + 3]));
	else if (!ft_strncmp(&line[i], "WE ", 3))
		return (extract_path(&(t_map->w_text), &line[i + 3]));
	else if (!ft_strncmp(&line[i], "EA ", 3))
		return (extract_path(&(t_map->e_text), &line[i + 3]));
	else if (!ft_strncmp(&line[i], "F ", 2))
		return (extract_color(&(t_map->floor_color), &line[i + 2]));
	else if (!ft_strncmp(&line[i], "C ", 2))
		return (extract_color(&(t_map->sky_color), &line[i + 2]));
	return (false);
}

bool	parse_line(t_mapinfo *t_map, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (true);
	if (t_map->map_line[0] != '\0')
	{
		if (!is_maze_line(line))
			return (ft_putstr_fd("Error: Incorrect map\n", 2), false);
		return (create_maze_line(t_map, line));
	}
	if (check_type(t_map, line, i))
		return (true);
	if (is_maze_line(line))
		return (create_maze_line(t_map, line));
	ft_putstr_fd("Error: Unknowns type\n", 2);
	return (false);
}

t_mapinfo	*parse_map(int fd)
{
	t_mapinfo	*t_map;
	char		*line;

	t_map = init_map();
	if (!t_map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(t_map, line) == false)
		{
			clean_gnl_stash(line, fd);
			free_mapinfo(t_map);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!checklist_mapinfo(t_map))
		return (free_mapinfo(t_map),
			ft_putstr_fd("Error: information missing\n", 2), NULL);
	if (!init_maze(t_map))
		return (free_mapinfo(t_map), NULL);
	return (t_map);
}
