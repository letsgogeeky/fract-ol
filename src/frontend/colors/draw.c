#include "frontend.h"


void ft_pixel(void *img, int x, int y, int32_t estimator, t_fractol *env)
{
	int color;
	if (estimator == env->estimator_max)
	{
		mlx_put_pixel(img, x, y, 0x000000FF);
	}
	else
	{
		color = get_rgba((estimator * env->color_scale->red / env->estimator_max), \
			(estimator * env->color_scale->green / env->estimator_max), (estimator * env->color_scale->blue / env->estimator_max),\
			(estimator * env->color_scale->transparency / env->estimator_max));
		mlx_put_pixel(img, x, y, color * estimator);
	}
}

void compute_frame(t_fractol *env)
{
	mlx_image_t *img;
	int x;
	int y;
	t_complex *z;
	int n;
	t_complex *c;

	img = (mlx_image_t *)env->current_frame;
	z = (t_complex *)malloc(sizeof(t_complex*));
	c = (t_complex *)malloc(sizeof(t_complex*));
	x = 0;
	y = 0;

	while (y < env->height)
	{
		while (x < env->width)
		{
			if (env->f_type == JULIA)
			{
				n = compute_julia_pixel(env, z, c, x, y);
			}
			else if (env->f_type == MANDELBROT)
			{
				n = compute_mandelbrot_pixel(env, z, c, x, y);
			}
			ft_pixel(img, x, y, n, env);
			x++;
		}
		x = 0;
		y++;
	}
}