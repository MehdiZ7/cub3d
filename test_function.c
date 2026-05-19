/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:04:33 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/30 17:45:14 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_mapinfo *t_map)
{
	printf("------- TEST PATH TEXTURE ---------\n");
	printf("NORTH : [%s]\n", t_map->n_text);
	printf("SOUTH  : [%s]\n", t_map->s_text);
	printf("WEST: [%s]\n", t_map->w_text);
	printf("EAST  : [%s]\n", t_map->e_text);
	printf("FLOOR  : %d\n", t_map->floor_color);
	printf("SKY  : %d\n", t_map->sky_color);
	printf("Maze  : %s\n", t_map->map_line);
	printf("------- TEST PATH TEXTURE END ---------\n");

}
