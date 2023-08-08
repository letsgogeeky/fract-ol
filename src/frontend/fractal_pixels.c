/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:10:37 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 17:27:00 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

void	draw_multibrot(t_fractol *env)
{
	int			x;
	int			y;
	int			n;
	t_complex	z;
	t_complex	c;

	set_complex(&c, 0, 0);
	set_complex(&z, 0, 0);
	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			n = compute_multibrot_pixel(env, z, x, y);
			smash_pixel(x, y, n, env);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_julia(t_fractol *env)
{
	int			x;
	int			y;
	int			n;
	t_complex	z;

	set_complex(&z, 0, 0);
	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			n = compute_julia_pixel(env, z, x, y);
			smash_pixel(x, y, n, env);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_mandelbrot(t_fractol *env)
{
	int			x;
	int			y;
	int			n;
	t_complex	z;
	t_complex	c;

	set_complex(&c, 0, 0);
	set_complex(&z, 0, 0);
	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			n = compute_mandelbrot_pixel(env, z, x, y);
			smash_pixel(x, y, n, env);
			x++;
		}
		x = 0;
		y++;
	}
}
