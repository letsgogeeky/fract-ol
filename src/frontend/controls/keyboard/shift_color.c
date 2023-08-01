#include "frontend.h"

void	control_red(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL && env->color_scale->red < 255)
		env->color_scale->red += 10;
	else if (env->color_scale->red > 0)
			env->color_scale->red -= 10;
}

void	control_green(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL && env->color_scale->green < 255)
			env->color_scale->green += 10;
	else if (env->color_scale->green > 0)
			env->color_scale->green -= 10;
}

void	control_blue(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL && env->color_scale->blue < 255)
			env->color_scale->blue += 10;
	else if (env->color_scale->blue > 0)
			env->color_scale->blue -= 10;
}

void	control_transparency(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL && env->color_scale->transparency < 255)
			env->color_scale->transparency += 10;
	else if (env->color_scale->transparency > 0)
			env->color_scale->transparency -= 10;
}
