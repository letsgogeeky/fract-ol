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
    double                  real_min;
    double                  real_max;
    double                  imaginary_min;
    double                  imaginary_max;
    int                     estimator_max;
    int                     width;
    int                     height;
    double                  radius;
    double                  pixel_size;
    float                   shift_val;
    t_zoom                  *zoom;
    t_color                 *color_scale;
    mlx_image_t             *current_frame;
    mlx_t                   *mlx;
	bool					should_draw;
}   t_fractol;

typedef void    (*t_fractol_loop_func)(void *param);

t_fractol   *init_env(int argc, char **argv);

#endif