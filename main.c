/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:41:42 by jhleena           #+#    #+#             */
/*   Updated: 2021/08/24 14:59:14 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_key_hook(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win, 4, 0, zoom, mlx);
	mlx_hook(mlx->mlx_win, 6, 0, julia_motion, mlx);
	mlx_hook(mlx->mlx_win, 2, 0, change_color, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, my_exit, mlx);
}

int	equal(char *str, char *f_name)
{
	while (*str && *f_name)
	{
		if (*str != *f_name)
			return (FALSE);
		++str;
		++f_name;
	}
	return (TRUE);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_start(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 800, 800, "Fract-ol");
	mlx->img.img = mlx_new_image(mlx->mlx, 800, 800);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	mlx->var.min = fill_comp(-2.0, -2.0);
	mlx->var.max = fill_comp(2.0, 2.0);
	mlx->color = 0;
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (!(argc == 2))
		return (write(1, "Error: enter Mandelbrot/Julia\n", 30), -1);
	if (equal(*(argv + 1), "Mandelbrot"))
	{
		mlx_start(&mlx);
		mlx.f = 'm';
		draw_fractal(&mlx, &mandelbrot_iteartions);
	}
	else if (equal(*(argv + 1), "Julia"))
	{
		mlx_start(&mlx);
		mlx.k = fill_comp(-0.4, 0.6);
		mlx.f = 'j';
		draw_fractal(&mlx, &julia_iteartions);
	}
	else
		write(1, "Error: wrong arguments, enter Mandelbrot/Julia", 46);
	my_mlx_key_hook(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
