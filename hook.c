/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:27:58 by jhleena           #+#    #+#             */
/*   Updated: 2021/08/24 14:55:54 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	interpolate(double mouse, double min_max, double interpolation)
{
	return (mouse + ((min_max - mouse) * interpolation));
}

int	zoom(int keykode, int x, int y, t_mlx *mlx)
{
	t_complex	mouse;
	double		interpolation;
	double		zoom;

	if (keykode == 4 || keykode == 5)
	{
		mouse = fill_comp((double)x / (800 / (mlx->var.max.re
						- mlx->var.min.re)) + mlx->var.min.re, (double)y / (800
					/ (mlx->var.max.im - mlx->var.min.im))
				* -1 + mlx->var.max.im);
		zoom = 1.20;
		if (keykode == 4)
			zoom = 0.80;
		interpolation = 1.0 / zoom;
		mlx->var.min.re = interpolate(mouse.re, mlx->var.min.re, interpolation);
		mlx->var.min.im = interpolate(mouse.im, mlx->var.min.im, interpolation);
		mlx->var.max.re = interpolate(mouse.re, mlx->var.max.re, interpolation);
		mlx->var.max.im = interpolate(mouse.im, mlx->var.max.im, interpolation);
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		if (mlx->f == 'm')
			draw_fractal(mlx, mandelbrot_iteartions);
		else if (mlx->f == 'j')
			draw_fractal(mlx, julia_iteartions);
	}	
	return (0);
}

int	julia_motion(int x, int y, t_mlx *mlx)
{
	if (mlx->f == 'j')
	{
		mlx->k = fill_comp(
				4 * ((double)x / 800 - 0.5),
				4 * ((double)(800 - y) / 800 - 0.5));
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		draw_fractal(mlx, julia_iteartions);
	}
	return (0);
}

int	change_color(int keykode, t_mlx *mlx)
{
	int static	color_ = 0;

	if (keykode == 49)
	{
		++color_;
		mlx->color = (color_ % 3) * 100;
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		if (mlx->f == 'm')
			draw_fractal(mlx, mandelbrot_iteartions);
		else if (mlx->f == 'j')
			draw_fractal(mlx, julia_iteartions);
	}
	else if (keykode == 53)
		exit(1);
	return (0);
}

int	my_exit(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx, (mlx->img).img);
	exit(0);
}
