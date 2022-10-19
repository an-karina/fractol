/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:42:10 by jhleena           #+#    #+#             */
/*   Updated: 2021/08/21 18:34:37 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iteartions(struct s_complex z, t_mlx *mlx)
{
	int	iterations;

	iterations = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iterations < 51)
	{
		z = fill_comp(pow(z.re, 2.0) - pow(z.im, 2.0) + (mlx->k).re,
				2.0 * z.re * z.im + (mlx->k).im);
		iterations++;
	}
	return (iterations);
}
