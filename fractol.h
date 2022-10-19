/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:31:55 by jhleena           #+#    #+#             */
/*   Updated: 2021/08/24 14:52:42 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define TRUE 1
# define FALSE 0

# include <math.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <stdlib.h>

typedef struct s_complex
{
	float	re;
	float	im;
}				t_complex;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_fractol
{
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	z;
}				t_fractol;

typedef struct s_mlx
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	int			x;
	int			y;
	t_complex	k;
	t_complex	c;
	t_fractol	var;
	char		f;
	int			color;
}				t_mlx;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}				t_color;

t_complex	fill_comp(float x, float y);
t_complex	c_sum(t_complex z_1, t_complex z_2);
int			c_abs(t_complex z);
int			c_sqr(t_complex z);
int			rgb_int(t_color color);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			julia_iteartions(struct s_complex z, t_mlx *mlx);
int			mandelbrot_iteartions(struct s_complex z, t_mlx *mlx);
void		draw_fractal(t_mlx *mlx,
				int (*fractal)(struct s_complex z, t_mlx *mlx));
int			zoom(int keykode, int x, int y, t_mlx *mlx);
int			julia_motion(int x, int y, t_mlx *mlx);
int			change_color(int keykode, t_mlx *mlx);
int			my_exit(t_mlx *mlx);

#endif
