/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backend.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 05:55:45 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 00:17:18 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKEND_H
# define BACKEND_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "fractol.h"
# include "baselib.h"

/**
 * Performs complex number multiplication.
 *
 * This function takes a pointer to a t_complex structure representing a complex
 * number and multiplies it with itself in a complex multiplication operation.
 * The function modifies the input complex number to store the result of the
 * multiplication. The complex multiplication operation is defined as follows:
 *
 * z = (a + bi) * (a + bi) = (a^2 - b^2) + (2 * a * b)i
 *
 * The function updates the 'real' and 'imag' components of the input complex
 * number to store the result of the multiplication operation.
 *
 * @param complex A pointer to the t_complex structure representing the complex
 * number to be multiplied.
 */
void        complex_multiply(t_complex *complex);

/**
 * Multiplies two complex numbers immutably.
 *
 * This function takes two complex numbers `a` and `b`, and returns a new complex
 * number that is the result of multiplying them together.
 *
 * @param a The first complex number.
 * @param b The second complex number.
 * @return A new complex number representing the product of `a` and `b`.
 */
t_complex   complex_multiply_immutable(t_complex a, t_complex b);

/**
 * Performs complex number addition.
 *
 * This function takes a pointer to a t_complex structure representing a complex
 * number 'original' and a constant pointer to another t_complex structure 'c'.
 * The function adds the 'real' and 'imag' components of the 'c' complex number
 * to the corresponding components of the 'original' complex number.
 *
 * The complex addition operation is defined as follows:
 *
 * z = (a + bi) + (c + di) = (a + c) + (b + d)i
 *
 * The function updates the 'real' and 'imag' components of the 'original'
 * complex number with the sum of the corresponding components from 'c'.
 *
 * @param original A pointer to the t_complex structure representing the original
 * complex number.
 * @param c A constant pointer to the t_complex structure representing the complex
 * number to be added.
 */
void        complex_add(t_complex *original, const t_complex *c);

/**
 * Adds two complex numbers immutably.
 *
 * This function takes two complex numbers `original` and `c`, and returns a new
 * complex number that is the result of adding them together.
 *
 * @param original The original complex number.
 * @param c The complex number to be added.
 * @return A new complex number representing the sum of `original` and `c`.
 */
t_complex	complex_add_immutable(t_complex original, t_complex c);
void		complex_pow_3(t_complex *complex);
void		complex_subtract(t_complex *c1, t_complex *c2);
t_complex	*complex_subtract_immutable(t_complex *c1, t_complex c2);
void        set_complex(t_complex *point, double real, double imaginary);
t_complex	*complex_divide(t_complex *numerator, t_complex	*denominator);
void		complex_multiply_scalar(t_complex *complex, int scalar);
t_complex   *complex_copy(t_complex *original);
void        print_complex(t_complex *complex);
void        update_pixel_size(t_fractol *env);

/**
 * Computes the number of iterations required for a Mandelbrot fractal at a
 * specific pixel position.
 *
 * This function calculates the number of iterations (n) required for the
 * specified pixel (x, y) in the Mandelbrot fractal. The Mandelbrot fractal
 * represents points in the complex plane, where each point is iterated to
 * determine whether it belongs to the Mandelbrot set. The function uses the
 * formula: z(n+1) = z(n)^2 + c, where z is a complex number, and c is a
 * constant complex number derived from the pixel coordinates and the zoom level.
 * The function stops iterating if the magnitude of z becomes greater than 2 or
 * the maximum number of iterations (env->estimator_max) is reached.
 *
 * @param env A pointer to the t_fractol structure containing fractal settings.
 * @param z A pointer to the complex number z, which is iterated in the Mandelbrot formula.
 * @param c A pointer to the constant complex number c, derived from the pixel coordinates.
 * @param x The x-coordinate of the pixel in the image.
 * @param y The y-coordinate of the pixel in the image.
 * @return The number of iterations (n) required to determine if the pixel belongs to the Mandelbrot set.
 */
int         compute_mandelbrot_pixel(t_fractol *env, t_complex *z, \
                                     t_complex *c, uint32_t x, uint32_t y);


/**
 * Computes the number of iterations required for a Julia fractal at a specific
 * pixel position.
 *
 * This function calculates the number of iterations (n) required for the specified
 * pixel (x, y) in the Julia fractal. The Julia fractal is created by iterating
 * a complex number z through the formula: z(n+1) = z(n)^2 + c, where c is a constant
 * complex number defined in the environment (env) settings. The function starts with
 * an initial complex number z derived from the pixel coordinates and the zoom level.
 * The iteration continues until the magnitude of z becomes greater than the square
 * of the radius (env->radius * env->radius) or the maximum number of iterations
 * (env->estimator_max) is reached.
 *
 * @param env A pointer to the t_fractol structure containing fractal settings.
 * @param z A pointer to the complex number z, which is iterated in the Julia fractal formula.
 * @param c A pointer to the constant complex number c, defined in the environment settings.
 * @param x The x-coordinate of the pixel in the image.
 * @param y The y-coordinate of the pixel in the image.
 * @return The number of iterations (n) required to determine if the pixel belongs to
 * the Julia set.
 */
int         compute_julia_pixel(t_fractol *env, t_complex *z, \
                                uint32_t x, uint32_t y);

int         compute_multibrot_pixel(t_fractol *env, t_complex *z, \
                                    t_complex *c, uint32_t x, uint32_t y);

void	set_border_matrix(t_fractol *env);
void    print_boundaries(t_fractol *env);
void    terminate_app(t_fractol *env);
#endif
