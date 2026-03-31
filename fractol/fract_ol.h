/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:36:51 by mzouhir           #+#    #+#             */
/*   Updated: 2026/01/05 10:56:47 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SIDE_LEN 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define MAGENTA 0xFF00FF
# define LIME 0xCCFF00
# define PURPLE 0x660066
# define AQUA 0x33CCCC
# define PINK 0xFF66B2
# define THUNDER 0x0066FF
# define LAVA 0xFF3300

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixel_ptr;
	int		bit_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*name;
	int		color;
	t_img	img;
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	int		iteration;
	double	julia_x;
	double	julia_y;
}	t_mlx_data;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

//parsing the input
int			check_input(int ac, char **av);

//Creation of the window
int			create_window(t_mlx_data *data);
void		clear_window(t_mlx_data *data);

//Handling input and events
void		events_init(t_mlx_data *data);

//calculating the fractal
void		fractal_calcul(t_mlx_data *data);
void		fractal_calcul_julia(t_mlx_data *data);
void		fractal_calcul_burning(t_mlx_data *data);

//math utils
double		scaled_map(double unscaled, double new_min,
				double new_max, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

#endif
