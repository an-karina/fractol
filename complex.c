/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:32:02 by jhleena           #+#    #+#             */
/*   Updated: 2021/08/21 18:29:36 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	fill_comp(float x, float y)
{
	return ((t_complex){x, y});
}

t_complex	c_sum(t_complex z_1, t_complex z_2)
{
	t_complex	result;

	result.re = z_1.re + z_2.re;
	result.re = z_2.im + z_2.im;
	return (result);
}

int	c_abs(t_complex z)
{
	return (sqrt(z.im * z.im + z.re * z.re));
}

int	c_sqr(t_complex z)
{
	return (z.im * z.im + z.re * z.re);
}
