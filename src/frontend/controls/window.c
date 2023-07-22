#include "frontend.h"

void ft_window_resize_hook(int32_t width, int32_t height, void * param)
{
    t_fractol *env;
    env = (t_fractol *)param;

    printf("%s\n", env->name);
    env->width = width;
    env->height = height;
	printf("width: %d | height: %d\n", width, height);
}

void window_exit_hook(void *param)
{
    t_fractol *env;

    env = (t_fractol *)param;
    free(env->name);
    free(env);
}