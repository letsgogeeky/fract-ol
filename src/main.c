#include "fractol.h"
#include "ft_complex.h"

#define WIDTH 900
#define HEIGHT 900

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

static void ft_pixel(void *img, int x, int y, uint32_t color)
{
	mlx_put_pixel(img, x, y, color);

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
	}
	else
	{
		if (is_equal_str(argv[1], "mandelbro"))
		{
			printf("Yaaay it's mandelbrot");
			env->f_type = MANDELBROT;
		}
		else if (is_equal_str(argv[1], "julia"))
		{
			printf("Yaaay it's Julia!!");
			env->f_type = JULIA;
		}
	}
	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	int x;
	int y;
	t_complex *z;
	int n;
	t_complex *c;
	double re_min;
	double	re_max;
	double im_max;
	double	pixel_size;
	double r;
	re_min = -2;
	re_max = 1;
	im_max = 1;
	z = (t_complex *)malloc(sizeof(t_complex*));
	c = (t_complex *)malloc(sizeof(t_complex*));

	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 900, 900);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// ft_pixel(img, 10, 10);
	x = 0;
	y = 0;
	r = 20;
	pixel_size = (double)(re_max - re_min) / mlx->width;
	while (y < mlx->height)
	{
		while (x < mlx->width)
		{
			if (env->f_type == JULIA)
			{
				z->real = re_min + (x * pixel_size);
				z->imag = im_max - (y * pixel_size);
				c->real = 0.4;
				c->imag = 0.3;
				n = 0;
				while (n < 50)
				{
					if (sqrt((z->real * z->real) + (z->imag * z->imag)) > r * r)
						break ;
					complex_multiply(z);
					complex_add(z, c);
					n++;
				}
				if (n == 50)
				{
					ft_pixel(img, x, y, 0x10000005);
				}
				else
				{
					ft_pixel(img, x, y, 0x10000005 * n * n * n * n * n);
				}
			}
			else if (env->f_type == MANDELBROT)
			{
				c->real = re_min + (x * pixel_size);
				c->imag = im_max - (y * pixel_size);
				z->real = 0;
				z->imag = 0;
				n = 0;
				while (n < 100)
				{
					if (sqrt((z->real * z->real) + (z->imag * z->imag)) > (re_max - re_min))
						break ;
					complex_multiply(z);
					complex_add(z, c);
					n++;
				}
				if (n == 100)
				{
					ft_pixel(img, x, y, 0xFF0000FF);
				}
				else
				{
					ft_pixel(img, x, y, 0xFFAA00FF);
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	ft_hook(mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}