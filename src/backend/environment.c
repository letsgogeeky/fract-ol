#include "backend.h"

void    update_pixel_size(t_fractol *env)
{
    env->pixel_size = (double)(env->real_max - env->real_min) / env->width;
}