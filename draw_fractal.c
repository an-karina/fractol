/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:33:57 by jhleena           #+#    #+#             */
/*   Updated: 2021/08/24 14:36:21 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	get_color(int iterations, int const_)
{
	double	t;
	t_color	color;

	t = (float)iterations / (float)50;
	color.r = (int)(9 * (1 - t) * pow(t, 3) * 255) + const_;
	color.g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255) + const_;
	color.b = (int)(8.5 * pow((1 - t), 3) * t * 255) + const_;
	return (color);
}

void	draw_fractal(t_mlx *mlx, int (*fractal)(struct s_complex z, t_mlx *mlx))
{
	int			iterations;
	t_color		color;

	mlx->var.factor = fill_comp((mlx->var.max.re - mlx->var.min.re) / 799,
			(mlx->var.max.im - mlx->var.min.im) / 799);
	mlx->y = 0;
	while (mlx->y < 800)
	{
		mlx->x = 0;
		mlx->c.im = mlx->var.max.im - mlx->y * mlx->var.factor.im;
		while (mlx->x < 800)
		{
			mlx->c.re = mlx->var.min.re + mlx->x * mlx->var.factor.re;
			mlx->var.z = fill_comp(mlx->c.re, mlx->c.im);
			iterations = fractal(mlx->var.z, mlx);
			my_mlx_pixel_put(&mlx->img, mlx->x, mlx->y,
				rgb_int(get_color(iterations, mlx->color)));
			++(mlx->x);
		}
		++(mlx->y);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
}
