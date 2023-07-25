#include "frontend.h"

void ft_scroll_hook(double delta_x, double delta_y, void * param)
{
    t_fractol *env;

    env = (t_fractol *)param;
    env->zoom->factor = env->zoom->factor + (delta_y / 1000);
    env->real_min = env->zoom->real_center - (env->zoom->factor * (env->zoom->real_center - env->real_min));
    env->real_max = env->zoom->real_center + (env->zoom-> factor * (env->real_max - env->zoom->real_center));
    env->imaginary_min = env->zoom->imaginary_center - (env->zoom->factor * (env->zoom->imaginary_center - env->imaginary_min));
    env->imaginary_max = env->zoom->imaginary_center + (env->zoom->factor * (env->imaginary_max - env->zoom->imaginary_center));
    env->pixel_size_x = (double)(env->real_max - env->real_min) / env->width;
    env->pixel_size_y = (double)(env->imaginary_max - env->imaginary_min) / env->height;
    compute_frame(env);
	printf("delta x: %f | delta y: %f\n", delta_x, delta_y);
}
