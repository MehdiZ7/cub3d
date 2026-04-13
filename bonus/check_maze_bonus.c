/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maze_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:11:22 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/13 12:10:12 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ' || c == '2')
		return (true);
	return (false);
}

bool	is_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	check_char_map(t_mapinfo *t_map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (t_map->map[i])
	{
		j = 0;
		while (t_map->map[i][j])
		{
			if (!valid_char(t_map->map[i][j]))
				return (false);
			if (is_position(t_map->map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (false);
	return (true);
}
