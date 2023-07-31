#include "frontend.h"
#include "fractol.h"


void ft_window_resize_hook(int32_t width, int32_t height, void * param)
{
    t_fractol *env;
    env = (t_fractol *)param;

    printf("%s\n", env->name);
    env->width = width;
    env->height = height;
    // compute_frame(env);
	mlx_delete_image(env->mlx, env->current_frame);
	mlx_image_t* img = mlx_new_image(env->mlx, env->width, env->height);
	if (!img || (mlx_image_to_window(env->mlx, img, 0, 0) < 0))
		return ;
	env->current_frame = img;
	printf("width: %d | height: %d\n", width, height);
	env->should_draw = true;
}

void window_exit_hook(void *param)
{
    t_fractol *env;

    env = (t_fractol *)param;
    free(env->name);
    free(env);
}