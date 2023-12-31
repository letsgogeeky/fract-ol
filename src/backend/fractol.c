/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:26:41 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 17:14:44 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"

int	in_bound(t_complex p, double boundary)
{
	if ((p.real * p.real) + (p.imag * p.imag) >= boundary)
		return (0);
	return (1);
}

int	compute_mandelbrot_pixel(t_fractol *env, t_complex z, \
					uint32_t x, uint32_t y)
{
	t_complex	c;
	int			n;

	c.real = env->real_min + (x * env->pixel_size);
	c.imag = env->imaginary_max - (y * env->pixel_size);
	set_complex(&z, 0, 0);
	n = 0;
	while (n < env->estimator_max)
	{
		if (!in_bound(z, 4))
			break ;
		complex_multiply(&z);
		complex_add(&z, &c);
		n++;
	}
	return (n);
}

int	compute_julia_pixel(t_fractol *env, t_complex z, uint32_t x, uint32_t y)
{
	int	n;

	z.real = env->real_min + (x * env->pixel_size);
	z.imag = env->imaginary_max - (y * env->pixel_size);
	n = 0;
	while (n < env->estimator_max)
	{
		if (!in_bound(z, env->radius))
			break ;
		complex_multiply(&z);
		complex_add(&z, &env->julia_c);
		n++;
	}
	return (n);
}

int	compute_multibrot_pixel(t_fractol *env, t_complex z, \
							uint32_t x, uint32_t y)
{
	t_complex	z_powered;
	t_complex	add_c;
	t_complex	c;
	int			n;
	int			p;

	set_complex(&c, env->real_min + (x * env->pixel_size), \
		env->imaginary_max - (y * env->pixel_size));
	set_complex(&z, 0, 0);
	n = 0;
	while (n < env->estimator_max)
	{
		p = 0;
		z_powered.real = z.real;
		z_powered.imag = z.imag;
		while (p++ < env->multibrot_n)
			z_powered = complex_multiply_immutable(z_powered, z);
		add_c = complex_add_immutable(z_powered, c);
		set_complex(&z, add_c.real, add_c.imag);
		if (!in_bound(z, 4))
			break ;
		n++;
	}
	return (n);
}
