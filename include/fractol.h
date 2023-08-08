/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 05:58:40 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 13:03:32 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "MLX42/MLX42.h"

#define BLACK 0x000000FF
#define BORDER_COLOR 0xFFFFFFFF

enum FractolTypeEnum
{
    MANDELBROT,
    JULIA,
    MULTIBROT
};

typedef struct s_complex
{
    double real;
    double imag;
}   t_complex;

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
    t_complex               min;
    t_complex               max;
    double                  real_min;
    double                  real_max;
    double                  imaginary_min;
    double                  imaginary_max;
    int                     estimator_max;
    int                     width;
    int                     height;
    t_complex               julia_c;
    double                  radius;
    int                     multibrot_n;
    double                  pixel_size;
    float                   shift_val;
    t_zoom                  *zoom;
    t_color                 *color_scale;
    mlx_image_t             *current_frame;
    mlx_t                   *mlx;
    int                     **border;
	bool					should_draw;
}   t_fractol;

typedef void    (*t_fractol_loop_func)(void *param);

t_fractol   *init_env(int argc, char **argv);

#endif
