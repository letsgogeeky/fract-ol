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

void	control_details(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL)
			env->estimator_max += 20;
	else if (env->estimator_max > 30)
			env->estimator_max -= 20;
}

void ft_key_hook(mlx_key_data_t key, void * param)
{
	t_fractol *env;

	env = (t_fractol *)param;
	if(key.key == MLX_KEY_SPACE && key.action == MLX_RELEASE)
	{
		puts("The SPACE key was pressed!");
	}
	else if (key.key == MLX_KEY_R)
		control_red(key, env);
	else if (key.key == MLX_KEY_G)
		control_green(key, env);
	else if (key.key == MLX_KEY_B)
		control_blue(key, env);
	else if (key.key == MLX_KEY_A)
		control_transparency(key, env);
	else if (key.key == MLX_KEY_D)
		control_details(key, env);
	compute_frame(env);
}
