#include "ft_complex.h"
#include "frontend.h"

#define WIDTH 1300
#define HEIGHT 900

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	ft_strlen(const char *c)
{
	int	size;

	size = 0;
	while (c[size] != '\0')
	{
		size++;
	}
	return (size);
}

int is_equal_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (!s1 && !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\n')
		i++;
	if (i < ft_strlen(s1))
		return (0);
	return (1);
}
int32_t	main(int argc, char **argv)
{
	t_fractol *env;

	env = (t_fractol *)malloc(sizeof(t_fractol *));

	if (argc < 2)
	{
		env->f_type = MANDELBROT;
		env->name = "Mandelbrot Fractol";
	}
	else
	{
		if (is_equal_str(argv[1], "mandelbrot"))
		{
			env->f_type = MANDELBROT;
			env->name = "Mandelbrot Fractol";
		}
		else if (is_equal_str(argv[1], "julia"))
		{
			env->f_type = JULIA;
			env->name = "Julia Fractol";
		}
	}
	env->estimator_max = 100;
	env->width = 1366;
	env->height = 768;
	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, env->name, true);
	
	int x;
	int y;
	t_complex *z;
	int n;
	t_complex *c;
	double	pixel_size;
	double r;
	env->real_min = -2;
	env->real_max = 1;
	env->imaginary_max = 1;
	z = (t_complex *)malloc(sizeof(t_complex*));
	c = (t_complex *)malloc(sizeof(t_complex*));

	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// ft_pixel(img, 10, 10);
	x = 0;
	y = 0;
	r = 23;
	pixel_size = (double)(env->real_max - env->real_min) / mlx->width;
	while (y < mlx->height)
	{
		while (x < mlx->width)
		{
			if (env->f_type == JULIA)
			{
				z->real = env->real_min + (x * pixel_size);
				z->imag = env->imaginary_max - (y * pixel_size);
				c->real = 0.5;
				c->imag = 0.3;
				n = 0;
				while (n < env->estimator_max)
				{
					if (sqrt((z->real * z->real) + (z->imag * z->imag)) > r * r)
						break ;
					complex_multiply(z);
					complex_add(z, c);
					n++;
				}
				ft_pixel(img, x, y, n, env);
			}
			else if (env->f_type == MANDELBROT)
			{
				c->real = env->real_min + (x * pixel_size);
				c->imag = env->imaginary_max - (y * pixel_size);
				z->real = 0;
				z->imag = 0;
				n = 0;
				while (n < 100)
				{
					if (sqrt((z->real * z->real) + (z->imag * z->imag)) > (env->real_max - env->real_min))
						break ;
					complex_multiply(z);
					complex_add(z, c);
					n++;
				}
				ft_pixel(img, x, y, n, env);
			}
			x++;
		}
		x = 0;
		y++;
	}
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(mlx, ft_key_hook, mlx);
	mlx_scroll_hook(mlx, ft_scroll_hook, mlx);
	mlx_resize_hook(mlx, ft_window_resize_hook, env);
	// mlx_set_window_size(mlx, env->width, env->height);
	// mlx_close_hook(mlx, window_exit_hook, env);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}