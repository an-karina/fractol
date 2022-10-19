/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:50:14 by jhleena           #+#    #+#             */
/*   Updated: 2021/08/24 14:48:12 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb_int(t_color color)
{
	return (256 * 256 * color.r + 256 * color.g
		+ color.b);
}

int	mandelbrot_iteartions(struct s_complex z, t_mlx *mlx)
{
	int	iterations;

	iterations = 0;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0) <= 4) && iterations < 80)
	{
		z = fill_comp(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ mlx->c.re, 2.0 * z.re * z.im + mlx->c.im);
		++iterations;
	}
	return (iterations);
}
