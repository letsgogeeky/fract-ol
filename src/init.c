/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:28:58 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/05 23:49:19 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"
#include "frontend.h"

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

static void set_env_fractol_mode(t_fractol *env, int argc, char **argv)
{
    if (argc < 2)
	{
		ft_printf("Please specify a Fractal of the following:\n");
		ft_printf("1. `mandelbrot`\n");
		ft_printf("2. `julia`\n");
		ft_printf("3. `kock` is shortcut for Koch Snowflake\n");
		free(env);
		exit(0);
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
		else if (is_equal_str(argv[1], "koch"))
		{
			env->f_type = KOCH;
			env->name = "KOCH SNOWFLAKE Fractol";
		}
		else if (is_equal_str(argv[1], "newton"))
		{
			env->f_type = NEWTON;
			env->name = "NEWTON Fractal";
		}
		else if (is_equal_str(argv[1], "ship"))
		{
			env->f_type = BURNINGSHIP;
			env->name = "BURNING SHIP Fractal";
		}
	}
}

void        set_env_boundaries(t_fractol *env)
{
    if (env->f_type == MANDELBROT || env->f_type == NEWTON || env->f_type == BURNINGSHIP)
    {
        env->real_min = -2.5;
        env->real_max = 2.5;
        env->imaginary_max = 1.5;
        env->imaginary_min = -1.5;
    }
    else if (env->f_type == JULIA)
    {
        env->real_min = -2;
        env->real_max = 1.8;
        env->imaginary_max = 1.3;
        env->imaginary_min = -1.5;
    }
}

void    set_zoom(t_fractol *env)
{
    env->zoom = (t_zoom *)malloc(sizeof(t_zoom));
    env->zoom->real_center = 0;
    env->zoom->imaginary_center = 0;
    env->zoom->factor = 1;
}

void    init_color(t_fractol *env)
{
    env->color_scale = (t_color *)malloc(sizeof(t_color));

    env->color_scale->red = 13;
    env->color_scale->green = 0;
    env->color_scale->blue = 255;
    env->color_scale->transparency = 70;
}

t_fractol   *init_env(int argc, char **argv)
{
    t_fractol	*env;
	int			i;

    env = (t_fractol *)malloc(sizeof(t_fractol));
	
	set_env_fractol_mode(env, argc, argv);
    set_env_boundaries(env);
	env->estimator_max = 100;
	env->width = 1366;
	env->height = 768;
    env->radius = 30;
	env->shift_val = 0.04;
	env->border = (int **)malloc(env->height * sizeof(int*));
	i = 0;
	while (i < env->height)
	{
		env->border[i] = (int *)malloc(env->width * sizeof(int));
		i++;
	}
    set_zoom(env);
    env->pixel_size = (double)(env->real_max - env->real_min) / env->width;
    init_color(env);
	env->should_draw = true;
    return (env);
}
