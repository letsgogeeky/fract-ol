/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:26:41 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/05 20:34:17 by ramoussa         ###   ########.fr       */
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
        if (sqrt((z->real * z->real) + (z->imag * z->imag)) > 2)
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
