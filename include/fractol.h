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
    int            estimator_max;
}   t_fractol;

#endif