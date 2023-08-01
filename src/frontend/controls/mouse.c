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
    // printf("%f\n", delta_x);
	(void) delta_x;
    if (delta_y > 0)
        env->zoom->factor = 0.97;
    else
        env->zoom->factor = 1.03;
    mouse_real = env->zoom->xpos / (env->width / (env->real_max - env->real_min)) + env->real_min;
    mouse_imaginary = env->zoom->ypos / (env->height / (env->imaginary_max - env->imaginary_min)) + env->imaginary_min;
    // printf("Mouse: Real = %f || Imaginary = %f\n", mouse_real, mouse_imaginary);
    interpolation = 1.0 / env->zoom->factor;
    env->real_min = interpolate(mouse_real, env->real_min, interpolation);
    env->real_max = interpolate(mouse_real, env->real_max, interpolation);
    env->imaginary_min = interpolate(mouse_imaginary, env->imaginary_min, interpolation);
    env->imaginary_max =  interpolate(mouse_imaginary, env->imaginary_max, interpolation);
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
    env->zoom->real_center = env->real_min + real_range * (env->width + env->zoom->xpos) / (2.0 * env->width);
    env->zoom->imaginary_center = env->imaginary_min + imaginary_range * (env->height + env->zoom->ypos) / (2.0 * env->height);
    // env->zoom->real_center = (xpos * env->pixel_size);
    // env->zoom->imaginary_center = (ypos * env->pixel_size);
}
