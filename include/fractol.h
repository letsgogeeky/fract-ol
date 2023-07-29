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

typedef struct s_zoom
{
    double  real_center;
    double  imaginary_center;
    double  factor;
    double  xpos;
    double  ypos;
}   t_zoom;

typedef struct s_color
{
    int red;
    int green;
    int blue;
    int transparency;
}   t_color;

typedef struct s_fractol
{
    enum FractolTypeEnum    f_type;
    char                    *name;
    float                  real_min;
    float                  real_max;
    float                  imaginary_min;
    float                  imaginary_max;
    int                     estimator_max;
    int                     width;
    int                     height;
    float                  radius;
    float                  pixel_size;
    t_zoom                  *zoom;
    t_color                 *color_scale;
    void                    *current_frame;
    mlx_t                   *mlx;
}   t_fractol;

t_fractol   *init_env(int argc, char **argv);

#endif