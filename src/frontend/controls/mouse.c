#include "frontend.h"

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void mouse_scroll_hook(double delta_x, double delta_y, void * param)
{
    t_fractol *env;
    double mouse_real;
    double mouse_imaginary;
    double interpolation;
    
    env = (t_fractol *)param;
    // env->zoom->factor = fabs(delta_y) * 50;
    // env->zoom->factor = 0.05;
    printf("%f\n", delta_x);
    if (delta_y > 0)
        env->zoom->factor = 0.97;
    else
        env->zoom->factor = 1.03;
    mouse_real = env->zoom->xpos / (env->width / (env->real_max - env->real_min)) + env->real_min;
    mouse_imaginary = env->zoom->ypos / (env->height / (env->imaginary_max - env->imaginary_min)) + env->imaginary_min;
    printf("Mouse: Real = %f || Imaginary = %f\n", mouse_real, mouse_imaginary);
    interpolation = 1.0 / env->zoom->factor;
    env->real_min = interpolate(mouse_real, env->real_min, interpolation);
    env->real_max = interpolate(mouse_real, env->real_max, interpolation);
    env->imaginary_min = interpolate(mouse_imaginary, env->imaginary_min, interpolation);
    env->imaginary_max =  interpolate(mouse_imaginary, env->imaginary_max, interpolation);
    // if(delta_y > 0)
    // {
    //     env->real_min -= ((env->real_max - env->real_min) * env->zoom->factor);
    //     env->real_max += ((env->real_max - env->real_min) * env->zoom->factor);
    //     env->imaginary_min -= ((env->imaginary_max- env->imaginary_min) * env->zoom->factor);
    //     env->imaginary_max += ((env->imaginary_max- env->imaginary_min) * env->zoom->factor);
    // }
    // else if (delta_y < 0)
    // {
    //     env->real_min += ((env->real_max - env->real_min) * env->zoom->factor);
    //     env->real_max -= ((env->real_max - env->real_min) * env->zoom->factor);
    //     env->imaginary_min += ((env->imaginary_max- env->imaginary_min) * env->zoom->factor);
    //     env->imaginary_max -= ((env->imaginary_max- env->imaginary_min) * env->zoom->factor);
    // }
    update_pixel_size(env);
    print_boundaries(env);
    // env->pixel_size += env->zoom->factor;
    
    
    // printf("Heey I'm clicked\n");
    // xdiff = env->zoom->xpos / (env->width / (env->real_max - env->real_min)) * -1 + env->real_max;
    // ydiff = env->zoom->ypos / (env->height / (env->imaginary_max - env->imaginary_min)) * -1 + env->imaginary_max;
    // printf("xdiff: %f || ydiff: %f\n", xdiff, ydiff);
    // // env->zoom->real_center += xdiff / 2.0;
    // // env->zoom->imaginary_center += ydiff / 2.0;
    // interpolation = 1.0 / env->zoom->factor;
    // env->real_min = (xdiff + ((env->real_min - xdiff) * interpolation));
    // env->real_max = (xdiff + ((env->real_max - xdiff) * interpolation));
    // env->imaginary_min = (ydiff + ((env->imaginary_min - ydiff) * interpolation));
    // env->imaginary_max = (ydiff + ((env->imaginary_max - ydiff) * interpolation));
    // env->real_min = env->zoom->real_center - (env->zoom->factor * (env->zoom->real_center - env->real_min));
    // env->real_max = env->zoom->real_center + (env->zoom-> factor * (env->real_max - env->zoom->real_center));
    // env->imaginary_min = env->zoom->imaginary_center - (env->zoom->factor * (env->zoom->imaginary_center - env->imaginary_min));
    // env->imaginary_max = env->zoom->imaginary_center + (env->zoom->factor * (env->imaginary_max - env->zoom->imaginary_center));
    // env->pixel_size = (double)(env->real_max - env->real_min) / env->width;
    // compute_frame(env);
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
    env->zoom->real_center = env->real_min + real_range * (env->width + env->zoom->xpos) / (2.0 * env->width);
    env->zoom->imaginary_center = env->imaginary_min + imaginary_range * (env->height + env->zoom->ypos) / (2.0 * env->height);
    // env->zoom->real_center = (xpos * env->pixel_size);
    // env->zoom->imaginary_center = (ypos * env->pixel_size);
}
