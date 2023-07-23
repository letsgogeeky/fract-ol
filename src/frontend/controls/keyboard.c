#include "frontend.h"

void ft_key_hook(mlx_key_data_t key, void * param)
{
	t_fractol *env;

	env = (t_fractol *)param;
	if(key.key == MLX_KEY_SPACE && key.action == MLX_RELEASE)
	{
		puts("The SPACE key was pressed!");
	}
	else if (key.key == MLX_KEY_R)
	{
		if (env->color_scale->red < 255)
		{
			env->color_scale->red += 10;
			compute_frame(env);
			puts("The R key was pressed!");
		}
	}
	else if (key.key == MLX_KEY_G)
	{
		if (env->color_scale->green < 255)
		{
			env->color_scale->green += 10;
			compute_frame(env);
			puts("The G key was pressed!");
			printf("new green: %d\n",env->color_scale->green);
		}
	}
	else if (key.key == MLX_KEY_B)
	{
		if (env->color_scale->blue < 255)
		{
			env->color_scale->blue += 10;
			compute_frame(env);
			puts("The B key was pressed!");
		}
	}
	else if (key.key == MLX_KEY_A)
	{
		if (env->color_scale->transparency < 255)
		{
			env->color_scale->transparency += 10;
			compute_frame(env);
			puts("The A key was pressed!");
		}
	}
}