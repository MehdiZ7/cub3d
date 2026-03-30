/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:08:37 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/30 10:28:08 by mzouhir          ###   ########.fr       */
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

t_mapinfo	*init_map(void)
{
	t_mapinfo	*t_map;

	t_map = malloc(sizeof(t_mapinfo));
	if (!t_map)
		return (NULL);
	t_map->n_text = NULL;
	t_map->s_text = NULL;
	t_map->e_text = NULL;
	t_map->w_text = NULL;
	t_map->floor_color = -1;
	t_map->sky_color = -1;
	t_map->map = NULL;
	t_map->map_width = -1;
	t_map->map_height = -1;
	return (t_map);
}

char	*extract_path(char **map_path, char *line)
{

}

void	parse_line(t_mapinfo *t_map, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
}

t_mapinfo	*parse_map(int fd)
{
	t_mapinfo	*t_map;
	char		*line;

	t_map = init_map();
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (t_map);
}


