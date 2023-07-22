#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "MLX42/MLX42.h"

enum FractolTypeEnum
{
    MANDELBROT,
    JULIA
};

typedef struct s_fractol
{
    enum FractolTypeEnum    f_type;
    char                    *name;
    int                     estimator_max;
    int32_t                 width;
    int32_t                 height;
    int32_t                 real_min;
    int32_t                 real_max;
    int32_t                 imaginary_max;
}   t_fractol;

#endif