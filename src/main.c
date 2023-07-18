#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fractol.h"

#define WIDTH 1200
#define HEIGHT 1200

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

void	print_complex(t_complex complex)
{
	printf("complex->real = %f || complex->imaginary = %f\n", complex.real, complex.imag);
}

void   complex_multiply(t_complex *complex)
{
    double   original_real;

	original_real = complex->real;
    complex->real = (original_real * original_real) - (complex->imag * complex->imag);
    complex->imag = (original_real * complex->imag) + (complex->imag * original_real);
}

void complex_add(t_complex *original, t_complex *c)
{
	original->real += c->real;
	original->imag += c->imag;
}


t_complex	*complex_copy(t_complex *original)
{
	t_complex *copied;

	copied = (t_complex *)malloc(sizeof(t_complex *));
	copied->real = original->real;
	copied->imag = original->imag;

	return(copied);
}

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	int x;
	int y;
	t_complex *z;
	int n;
	t_complex *c;
	double re_min;
	double	re_max;
	double im_max;
	double	pixel_size;
	// double temp_real;
	re_min = -2;
	re_max = 1;
	im_max = 1;
	z = (t_complex *)malloc(sizeof(t_complex*));
	c = (t_complex *)malloc(sizeof(t_complex*));

	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 1200, 1200);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// ft_pixel(img, 10, 10);
	x = 0;
	y = 0;
	pixel_size = (double)(re_max - re_min) / mlx->width;
	printf("Pixel Size = %f\n", pixel_size);
	while (y < mlx->height)
	{
		while (x < mlx->width)
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