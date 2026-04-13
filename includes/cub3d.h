/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:19:58 by mzouhir           #+#    #+#             */
/*   Updated: 2026/04/13 13:47:25 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line.h"

# define HEIGHT 600
# define WIDTH 800
# define SPEED 0.2
# define TURNSPEED 0.1
# define TILE_SIZE 7
# define PLAYER_SIZE 3
# define MAP_WALL 0xCCCCCC
# define MAP_FLOOR 0x333333
# define MAP_PLAYER 0xFF0000
# define MAP_OFFSET 10

typedef struct s_mapinfo
{
	char	*n_text;
	char	*s_text;
	char	*e_text;
	char	*w_text;
	char	*d_text;

	int		floor_color;
	int		sky_color;

	char	**map;
	char	*map_line;
	int		map_width;
	int		map_height;
}	t_mapinfo;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixel_ptr;
	int		bit_per_pixel;
	int		endian;
	int		line_len;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	cam_y;
}	t_player;

typedef struct s_render
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;

	double	sidedist_x;
	double	sidedist_y;

	double	deltadist_x;
	double	deltadist_y;

	int		step_x;
	int		step_y;

	bool	hit;
	int		side;

	double	perpwalldist;

	int		lineheight;
	int		drawstart;
	int		drawend;

	int		tex_id;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_render;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_mapinfo	*map;
	t_player	player;
	t_render	render;
	t_img		textures[5];
}	t_game;

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

//init game window
bool		launcher(t_game *game);
void		clear_window(t_game *game);
bool		init_textures(t_game *game);

//init player
void		init_player_pos(t_game *game);

//events
void		events_init(t_game *game);
bool		check_collision(t_game *game, double x, double y);
void		move_forback(int keysym, t_game *game);
void		move_rightleft(int keysym, t_game *game);
void		look_right(t_game *game);
void		look_left(t_game *game);

//drawing
void		my_pixel_put(t_game *game, int x, int y, int color);
void		draw_vertical_line(t_game *game, int x);

//Render
void		render_maths(t_game *game);
void		get_texture(t_game *game);
void		calcul_texture(t_game *game);

//BONUS minimap
void		render_minimap(t_game *game);

#endif
