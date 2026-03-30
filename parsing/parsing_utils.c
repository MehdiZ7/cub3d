/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:14:37 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/30 18:01:23 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mapinfo(t_mapinfo *t_map)
{
	if (!t_map)
		return ;
	if (t_map->n_text)
		free(t_map->n_text);
	if (t_map->s_text)
		free(t_map->s_text);
	if (t_map->e_text)
		free(t_map->e_text);
	if (t_map->w_text)
		free(t_map->w_text);
	if (t_map->map_line)
		free(t_map->map_line);
	if (t_map->map)
		free_tab(t_map->map);
	free(t_map);
}

void	clean_gnl_stash(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
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
	t_map->map_line = ft_strdup("");
	if (!t_map->map_line)
		return (free(t_map), NULL);
	t_map->map_width = -1;
	t_map->map_height = -1;
	return (t_map);
}

bool	checklist_mapinfo(t_mapinfo *t_map)
{
	if (!t_map->n_text)
		return (false);
	if (!t_map->s_text)
		return (false);
	if (!t_map->e_text)
		return (false);
	if (!t_map->w_text)
		return (false);
	if (t_map->floor_color == -1)
		return (false);
	if (t_map->sky_color == -1)
		return (false);
	if (t_map->map_line[0] == '\0')
		return (false);
	return (true);
}
