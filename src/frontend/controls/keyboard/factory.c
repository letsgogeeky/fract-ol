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
		control_red(key, env);
	else if (key.key == MLX_KEY_G)
		control_green(key, env);
	else if (key.key == MLX_KEY_B)
		control_blue(key, env);
	else if (key.key == MLX_KEY_A)
		control_transparency(key, env);
	else if (key.key == MLX_KEY_D)
		control_details(key, env);
	else if (key.key == MLX_KEY_LEFT)
		go_left(key, env);
	else if (key.key == MLX_KEY_RIGHT)
		go_right(key, env);
	else if (key.key == MLX_KEY_UP)
		go_up(key, env);
	else if (key.key == MLX_KEY_DOWN)
		go_down(key, env);
	compute_frame(env);
}