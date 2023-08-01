#include "backend.h"

void    update_pixel_size(t_fractol *env)
{
    env->pixel_size = (double)(env->real_max - env->real_min) / env->width;
}

void    terminate_app(t_fractol *env)
{
    mlx_delete_image(env->mlx, env->current_frame);
    mlx_terminate(env->mlx);
    free(env);
    exit(0);
}