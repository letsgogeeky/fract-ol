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
void compute_kochcurve(t_fractol *env, t_complex *a, t_complex *b, int level)
{
	int	delta_x;
	int	delta_y;
	t_complex	*c;
	t_complex	*d;
	t_complex	*e;

	if (level == 0)
	{
		mlx_put_pixel(env->current_frame, a->real, a->imag, 0xFFFFFFFF);
		mlx_put_pixel(env->current_frame, b->real, b->imag, 0xFFFFFFFF);
	}
	else
	{
		c = (t_complex *)malloc(sizeof(t_complex));
		d = (t_complex *)malloc(sizeof(t_complex));
		e = (t_complex *)malloc(sizeof(t_complex));
		delta_x = b->real - a->real;
		delta_y = b->imag - a->imag;
		set_complex(c, a->real + delta_x / 3, a->imag + delta_y / 3);
		set_complex(d, (int)(0.5 * (a->real + b->real) + sqrt(3) * (a->imag - b->imag) / 6), \
			(int)(0.5 * (a->imag + b->imag) + sqrt(3) * (b->real - a->real) / 6));
		set_complex(e, a->real + 2 * delta_x / 3, a->imag + 2 * delta_y / 3);
		compute_kochcurve(env, a, c, level - 1);
		compute_kochcurve(env, c, d, level - 1);
		compute_kochcurve(env, d, e, level - 1);
		compute_kochcurve(env, e, b, level - 1);
		free(c);
		free(d);
		free(e);
	}
}

void draw_kochcurve(t_fractol *env)
{
	int	level;
	int	width;
	t_complex	*a;
	t_complex	*b;
	t_complex	*c;

	level = 6;
	width = (int)(env->width / sqrt(2));

	a = (t_complex *)malloc(sizeof(t_complex));
	b = (t_complex *)malloc(sizeof(t_complex));
	c = (t_complex *)malloc(sizeof(t_complex));
 
	set_complex(a, env->width / 2 - width / 2, 1);
	set_complex(b, env->width / 2 + width / 2, 1);
	set_complex(c, env->width / 2, a->imag + width * sqrt(3) / 2);

	compute_kochcurve(env, a, b, level);
	compute_kochcurve(env, b, c, level);
	compute_kochcurve(env, c, a, level);

	free(a);
	free(b);
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
	else if (env->f_type == KOCH)
		draw_kochcurve(env);
	env->should_draw = false;
}
