/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:19:58 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/31 13:29:44 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_mapinfo
{
	char	*n_text;
	char	*s_text;
	char	*e_text;
	char	*w_text;

	int		floor_color;
	int		sky_color;

	char	**map;
	char	*map_line;
	int		map_width;
	int		map_height;
}	t_mapinfo;

//parsing map
bool		check_extension(char *str);
t_mapinfo	*parse_map(int fd);

//parsing color
bool		extract_color(int *map_color, char *line);

//parsing maze
bool		is_maze_line(char *line);
bool		create_maze_line(t_mapinfo *t_map, char *line);
bool		init_maze(t_mapinfo *t_map);
bool		check_char_map(t_mapinfo *t_map);
bool		is_position(char c);

//Floodfill algorithm
bool		validate_map(t_mapinfo *t_map);

//parsing utils
void		free_mapinfo(t_mapinfo *t_map);
void		clean_gnl_stash(char *line, int fd);
void		free_tab(char **tab);
t_mapinfo	*init_map(void);
bool		checklist_mapinfo(t_mapinfo *t_map);

//Testing functions
void		print_map(t_mapinfo *t_map);

#endif
