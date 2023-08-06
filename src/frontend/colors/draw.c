/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:45:46 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/06 23:29:45 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

int	compute_newton_pixel(t_fractol *env, t_complex *z, t_complex *c, uint32_t x, uint32_t y)
{
	int	n;
	// int	r_idx;
	t_complex *zcpy1;
	t_complex *zcpy2;
	// t_complex	*difference;
	// t_complex	roots[3] = 
	// {
	// 	{1, 0},
	// 	{-0.5, sqrt(3)/ 2.0},
	// 	{-0.5, -sqrt(3)/2.0}	
	// };
	// int		colors[3] =
	// {
	// 	0xFF0000FF,
	// 	0x00FF00FF,
	// 	0x0000FFFF
	// };

	n = 0;
	z->real = env->real_min + (x * env->pixel_size);
    z->imag = env->imaginary_max - (y * env->pixel_size);
	// z->real = (x - env->width / 2.0) / (env->width / 4.0);
    // z->imag = (y - env->height / 2.0) / (env->height / 4.0);
	c->real = 1;
	c->imag = 0;
	double tolerance = 0.000001;
	while (n < env->estimator_max)
    {
        zcpy1 = complex_copy(z);
		zcpy2 = complex_copy(z);
		complex_pow_3(zcpy1);
		complex_subtract(zcpy1, c);
		if (fabs(z->real) < tolerance && fabs(z->imag) < tolerance)
		{
			break ;
		}
		complex_multiply(zcpy2);
		complex_multiply_scalar(zcpy2, 3);
		zcpy1 = complex_divide(zcpy1, zcpy2);
		complex_subtract(z, zcpy1);
		// zcp1 = complex_divide()
		
		// r_idx = 0;
		// while (r_idx < 3)
		// {
		// 	difference = complex_subtract_immutable(z, roots[r_idx]);
		// 	// ft_printf("diff real: %f  diff imag: %f\n", difference->real, difference->imag);
		// 	// fflush(stdout);
		// 	// return 0;
		// 	if (fabs(difference->real) < tolerance && fabs(difference->imag) < tolerance)
		// 	{
		// 		return (colors[r_idx]);
		// 	}
		// 	r_idx++;
		// }
        n++;
    }
	return (n);
}

void draw_newton(t_fractol *env)
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
			n = compute_newton_pixel(env, z, c, x, y);
			// mlx_put_pixel(env->current_frame, x, y, n);
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
	set_border_matrix(env);
	while (y < env->height)
	{
		while (x < env->width)
		{
			if (env->border[y][x] == 1)
			{
				mlx_put_pixel(env->current_frame, x, y, BORDER_COLOR);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int		compute_burningship_pixel(t_fractol *env, t_complex *z, uint32_t x, uint32_t y)
{
	int	n;
	int	xtmp;
	z->real = env->real_min + (x * env->pixel_size);
    z->imag = env->imaginary_max - (y * env->pixel_size);
    n = 0;
    while (n < env->estimator_max)
    {
        if ((z->real * z->real) + (z->imag * z->imag) > 4.0)
            break ;
		xtmp = (z->real * z->real) - (z->imag * z->imag) + z->real;
		z->imag = fabs(2.0 * z->real * z->imag) + z->imag;
		z->real = xtmp;
        n++;
    }

	return (n);
}

void	draw_burningship(t_fractol *env)
{
	int x;
	int y;
	t_complex *z;
	int n;

	z = (t_complex *)malloc(sizeof(t_complex*));
	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			n = compute_burningship_pixel(env, z, x, y);
			if (n == env->estimator_max)
				mlx_put_pixel(env->current_frame, x, y, 0x000000FF);
			else
				mlx_put_pixel(env->current_frame, x, y, 0xFF0000FF);
			x++;
		}
		x = 0;
		y++;
	}
	free(z);
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
	else if (env->f_type == NEWTON)
		draw_newton(env);
	else if (env->f_type == BURNINGSHIP)
		draw_burningship(env);
	else if (env->f_type == MULTIBROT)
		draw_multibrot(env);
	env->should_draw = false;
}
