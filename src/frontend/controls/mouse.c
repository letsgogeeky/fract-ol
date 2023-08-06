/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:29:15 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/06 23:11:04 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void mouse_scroll_hook(double delta_x, double delta_y, void * param)
{
    t_fractol *env;
    double interpolation;
    
    env = (t_fractol *)param;
    // env->zoom->factor = fabs(delta_y) * 50;
    // env->zoom->factor = 0.05;
	(void) delta_x;
    if (delta_y > 0)
        env->zoom->factor = 0.97;
    else
        env->zoom->factor = 1.03;
    interpolation = 1.0 / env->zoom->factor;
    env->real_min = interpolate(env->zoom->real_center, env->real_min, interpolation);
    env->real_max = interpolate(env->zoom->real_center, env->real_max, interpolation);
    env->imaginary_min = interpolate(env->zoom->imaginary_center, env->imaginary_min, interpolation);
    env->imaginary_max =  interpolate(env->zoom->imaginary_center, env->imaginary_max, interpolation);
    update_pixel_size(env);
	env->should_draw = true;
}



void mouse_cursor_hook(double xpos, double ypos, void* param)
{
    t_fractol *env;
    double real_range;
    double imaginary_range;
    env = (t_fractol *)param;
    real_range = env->real_max - env->real_min;
    imaginary_range = env->imaginary_max - env->imaginary_min;
    env->zoom->xpos = xpos;
    env->zoom->ypos = ypos;
    env->zoom->real_center = env->zoom->xpos / (env->width / real_range) + env->real_min;
    env->zoom->imaginary_center = env->zoom->ypos / (env->height / imaginary_range) + env->imaginary_min;
}
