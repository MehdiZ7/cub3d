/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:28:34 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/31 12:40:22 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (true);
	return (false);
}

bool	ft_isnumber(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		count++;
	}
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (false);
	if (!count)
		return (false);
	return (true);
}

int	convert_rgb(char **rgb)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	if (!rgb)
		return (-1);
	while (rgb[i])
	{
		if (!ft_isnumber(rgb[i]))
			return (-1);
		i++;
	}
	if (i != 3)
		return (-1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

bool	extract_color(int *map_color, char *line)
{
	char	**rgb;
	int		color;

	if (!check_commas(line))
		return (false);
	if (*map_color != -1)
		return (ft_putstr_fd("Error\n Same color existing\n", 2), false);
	rgb = ft_split(line, ',');
	if (!rgb)
		return (ft_putstr_fd("Error\n Malloc failure", 2), false);
	color = convert_rgb(rgb);
	if (color < 0)
		return (free_tab(rgb), false);
	*map_color = color;
	free_tab(rgb);
	return (true);
}
