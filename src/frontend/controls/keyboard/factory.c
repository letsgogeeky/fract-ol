#include "frontend.h"

bool    is_arrow_key(mlx_key_data_t key)
{
    if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT \
        || key.key == MLX_KEY_UP || key.key == MLX_KEY_DOWN)
    {
        if(key.action == MLX_RELEASE)
            return (true);
    }
    return (false);
}

bool    is_color_key(mlx_key_data_t key)
{
    if (key.key == MLX_KEY_R || key.key == MLX_KEY_G \
        || key.key == MLX_KEY_B || key.key == MLX_KEY_A)
    {
        if(key.action == MLX_RELEASE)
            return (true);
    }
    return (false);
}

void    control_arrows(mlx_key_data_t key, t_fractol *env)
{
    if (key.key == MLX_KEY_LEFT)
		go_left(env);
	else if (key.key == MLX_KEY_RIGHT)
		go_right(env);
	else if (key.key == MLX_KEY_UP)
		go_up(env);
	else if (key.key == MLX_KEY_DOWN)
		go_down(env);
    update_pixel_size(env);
    env->should_draw = true;
}

void    control_colors(mlx_key_data_t key, t_fractol *env)
{
    if (key.key == MLX_KEY_R)
		control_red(key, env);
	else if (key.key == MLX_KEY_G)
		control_green(key, env);
	else if (key.key == MLX_KEY_B)
		control_blue(key, env);
	else if (key.key == MLX_KEY_A)
		control_transparency(key, env);
    env->should_draw = true;
}

void ft_key_hook(mlx_key_data_t key, void * param)
{
    t_fractol *env;

    env = (t_fractol*)param;
	if(key.key == MLX_KEY_SPACE && key.action == MLX_RELEASE)
	{
		puts("The SPACE key was pressed!");
	}
	else if (is_color_key(key))
        control_colors(key, env);
	else if (key.key == MLX_KEY_D && key.action == MLX_RELEASE)
		control_details(key, env);
	else if (is_arrow_key(key))
        control_arrows(key, env);
    else if (key.key == MLX_KEY_ESCAPE)
        terminate_app(env);
    else if (key.key == MLX_KEY_0 && key.action == MLX_RELEASE)
        draw_border(env);
}
