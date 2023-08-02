#include "frontend.h"

void smash_pixel(int x, int y, int32_t estimator, t_fractol *env)
{
	int color;

	color = 0x000000FF;
	if (estimator != env->estimator_max)
	{
		color = get_rgba((estimator * env->color_scale->red / env->estimator_max), \
			(estimator * env->color_scale->green / env->estimator_max), \
			(estimator * env->color_scale->blue / env->estimator_max),\
			(estimator * env->color_scale->transparency / env->estimator_max));
		estimator = estimator * 100;
		color *= estimator;
	}
	env->border[y][x] = color;
	mlx_put_pixel(env->current_frame, x, y, color);
}


void draw_julia(t_fractol *env)
{
	int x;
	int y;
	t_complex *z;
	int n;
	t_complex *c;

	z = (t_complex *)malloc(sizeof(t_complex*));
	c = (t_complex *)malloc(sizeof(t_complex*));
	x = 0;
	y = 0;
	set_complex(c, -0.74543, 0.11301);
	while (y < env->height)
	{
		while (x < env->width)
		{
			n = compute_julia_pixel(env, z, c, x, y);
			smash_pixel(x, y, n, env);
			x++;
		}
		x = 0;
		y++;
	}
	free(z);
	free(c);
}

void draw_mandelbrot(t_fractol *env)
{
	int x;
	int y;
	t_complex *z;
	int n;
	t_complex *c;

	z = (t_complex *)malloc(sizeof(t_complex*));
	c = (t_complex *)malloc(sizeof(t_complex*));
	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			n = compute_mandelbrot_pixel(env, z, c, x, y);
			smash_pixel(x, y, n, env);
			x++;
		}
		x = 0;
		y++;
	}
	free(z);
	free(c);
}

void	draw_border(t_fractol *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			if (env->border[y][x] == 0x000000FF)
			{
				if (x - 1 > 0 && x + 1 < env->width && y - 1 > 0 && y + 1 < env->height )
				{
					if (env->border[y][x + 1] != 0x000000FF)
						mlx_put_pixel(env->current_frame, x + 1, y, 0xFFFFFFFF);
					else if (env->border[y][x - 1] != 0x000000FF)
						mlx_put_pixel(env->current_frame, x - 1, y, 0xFFFFFFFF);
					else if (env->border[y + 1][x] != 0x000000FF)
						mlx_put_pixel(env->current_frame, x, y + 1, 0xFFFFFFFF);
					else if (env->border[y - 1][x] != 0x000000FF)
						mlx_put_pixel(env->current_frame, x, y - 1, 0xFFFFFFFF);
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void compute_frame(t_fractol *env)
{
	if (env->should_draw == false)
		return ;
	if (env->f_type == JULIA)
		draw_julia(env);
	else if (env->f_type == MANDELBROT)
		draw_mandelbrot(env);
	env->should_draw = false;
}
