#include "backend.h"
#include "frontend.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void print_env(t_fractol *env)
{
	printf("Width on env = %d\n", env->width);
	printf("env estimator = %d\n", env->estimator_max);
	printf("pixel size real: %f\n", env->pixel_size);
	printf("Real Min: %f        || Real Max: %f\n", env->real_min, env->real_max);
    printf("Imaginary Min: %f   || Imaginary Max: %f\n", env->imaginary_min, env->imaginary_max);
	printf("Zoom factor: %f\n", env->zoom->factor);
}

void register_hooks(mlx_t *mlx, t_fractol *env)
{
	mlx_key_hook(mlx, ft_key_hook, env);
	mlx_scroll_hook(mlx, mouse_scroll_hook, env);
	mlx_cursor_hook(mlx, mouse_cursor_hook, env);
	mlx_resize_hook(mlx, ft_window_resize_hook, env);
	mlx_close_hook(mlx, window_exit_hook, env);
}


int32_t	main(int argc, char **argv)
{
	t_fractol *env;
	
	env = init_env(argc, argv);
	mlx_t* mlx = mlx_init(env->width, env->height, env->name, true);
	if (!mlx)
		ft_error();
	env->mlx = mlx;
	mlx_image_t* img = mlx_new_image(mlx, env->width, env->height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	env->current_frame = img;
	print_env(env);
	mlx_loop_hook(mlx, (t_fractol_loop_func)compute_frame, env);
	register_hooks(mlx, env);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
