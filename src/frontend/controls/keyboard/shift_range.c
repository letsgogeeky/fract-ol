#include "frontend.h"

void	go_left(mlx_key_data_t key, t_fractol *env)
{
	double range;

	if (key.action == MLX_RELEASE)
	{
		range = env->real_max - env->real_min;
		env->real_min -= (range * 0.1);
		env->real_max -= (range * 0.1);
		compute_frame(env);
	}
		
}
void	go_right(mlx_key_data_t key, t_fractol *env)
{
	double range;
	if (key.action != MLX_RELEASE)
	{
		range = env->real_max - env->real_min;
		env->real_min += (range * 0.1);
		env->real_max += (range * 0.1);
		compute_frame(env);
	}
		
}
void	go_up(mlx_key_data_t key, t_fractol *env)
{
	double range;
	if (key.action != MLX_RELEASE)
	{
		range = env->imaginary_max - env->imaginary_min;
		env->imaginary_max += (range * 0.1);
		env->imaginary_min += (range * 0.1);
		compute_frame(env);
	}
		
}
void	go_down(mlx_key_data_t key, t_fractol *env)
{
	double range;
	if (key.action != MLX_RELEASE)
	{
		range = env->imaginary_max - env->imaginary_min;
		env->imaginary_max -= (range * 0.1);
		env->imaginary_min -= (range * 0.1);
		compute_frame(env);
	}
		
}