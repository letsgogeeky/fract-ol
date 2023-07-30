#ifndef COMPLEX_H
# define COMPLEX_H

#include <math.h>
#include <stdlib.h>
#include "fractol.h"

typedef struct s_complex
{
    double real;
    double imag;
}   t_complex;

void        complex_multiply(t_complex *complex);
void        complex_add(t_complex *original, const t_complex *c);
t_complex   *complex_copy(t_complex *original);
void        print_complex(t_complex *complex);
void        update_pixel_size(t_fractol *env);
int         compute_mandelbrot_pixel(t_fractol *env, t_complex *z, \
                                     t_complex *c, uint32_t x, uint32_t y);
int         compute_julia_pixel(t_fractol *env, t_complex *z, \
                                t_complex *c, uint32_t x, uint32_t y);

void    print_boundaries(t_fractol *env);
#endif