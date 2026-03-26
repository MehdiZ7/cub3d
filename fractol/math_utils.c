/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:02:54 by mzouhir           #+#    #+#             */
/*   Updated: 2026/01/05 10:48:53 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	scaled_map(double unscaled, double new_min,
	double new_max, double old_max)
{
	double	result;

	result = (new_max - new_min) * unscaled / old_max + new_min;
	return (result);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imaginary = z1.imaginary + z2.imaginary;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imaginary * z.imaginary;
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}
