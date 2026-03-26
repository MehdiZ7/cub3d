/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:19:58 by mzouhir           #+#    #+#             */
/*   Updated: 2026/03/26 18:49:39 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_mapinfo
{
	char	*n_text;
	char	*s_text;
	char	*e_text;
	char	*w_text;

	int		floor_color;
	int		sky_color;

	char	**map;
	int		map_width;
	int		map_height;
}	t_mapinfo;

#endif
