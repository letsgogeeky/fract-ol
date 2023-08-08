/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backend.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 05:55:45 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 13:23:42 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKEND_H
# define BACKEND_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "fractol.h"
# include "baselib.h"

void		complex_multiply(t_complex *complex);
t_complex	complex_multiply_immutable(t_complex a, t_complex b);
void		complex_add(t_complex *original, const t_complex *c);
t_complex	complex_add_immutable(t_complex original, t_complex c);
void		set_complex(t_complex *point, double real, double imaginary);
t_complex	*complex_copy(t_complex *original);
void		update_pixel_size(t_fractol *env);
int			compute_mandelbrot_pixel(
				t_fractol *env, t_complex z, \
				uint32_t x, uint32_t y);
int			compute_julia_pixel(t_fractol *env, t_complex z, \
				uint32_t x, uint32_t y);
int			compute_multibrot_pixel(t_fractol *env, t_complex z, \
				uint32_t x, uint32_t y);
void		set_border_matrix(t_fractol *env);
void		terminate_app(t_fractol *env);

#endif
