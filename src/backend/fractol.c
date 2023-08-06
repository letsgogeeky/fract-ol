/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:26:41 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/06 23:43:57 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"

int compute_mandelbrot_pixel(t_fractol *env, t_complex *z, t_complex *c, uint32_t x, uint32_t y)
{
    int n;

    c->real = env->real_min + (x * env->pixel_size);
    c->imag = env->imaginary_max - (y * env->pixel_size);
    z->real = 0;
    z->imag = 0;
    n = 0;
    while (n < env->estimator_max)
    {
        if ((z->real * z->real) + (z->imag * z->imag) >= 4)
            break ;
        complex_multiply(z);
        complex_add(z, c);
        n++;
    }
    return (n);
}

int compute_julia_pixel(t_fractol *env, t_complex *z, t_complex *c, uint32_t x, uint32_t y)
{
    int n;

    z->real = env->real_min + (x * env->pixel_size);
    z->imag = env->imaginary_max - (y * env->pixel_size);
    n = 0;
    while (n < env->estimator_max)
    {
        if (sqrt((z->real * z->real) + (z->imag * z->imag)) > env->radius * env->radius)
            break ;
        complex_multiply(z);
        complex_add(z, c);
        n++;
    }
    return (n);
}

int compute_multibrot_pixel(t_fractol *env, t_complex *z, t_complex *c, \
							uint32_t x, uint32_t y)
{
    int n;
	int p;

	set_complex(c, env->real_min + (x * env->pixel_size), env->imaginary_max - (y * env->pixel_size));
	set_complex(z, 0, 0);
    n = 0;
    while (n < env->estimator_max)
    {
		p = 0;
		t_complex z_powered;
		z_powered.real = z->real;
		z_powered.imag = z->imag;
		while (p < env->multibrot_n)
		{
			z_powered = complex_multiply_immutable(z_powered, *z);
			p++;
		}
		t_complex add_c = complex_add_immutable(z_powered, *c);
		set_complex(z, add_c.real, add_c.imag);
        if ((z->real * z->real) + (z->imag * z->imag) >= 4)
            break ;
        n++;
    }
    return (n);
}
