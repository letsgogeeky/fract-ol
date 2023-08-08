/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:28:58 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 18:59:36 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"
#include "frontend.h"

static void	abort_illegal_args(t_fractol *env)
{
	ft_printf("\033[1m\033[31m");
	ft_printf("UNKNOWN FRACTAL PASSED AS PARAM...!\n");
	show_program_options();
	free(env);
	exit(0);
}

static void	set_env_fractol_mode(t_fractol *env, int argc, char **argv)
{
	if (argc < 2 || ft_strlen(argv[1]) != 1)
		abort_illegal_args(env);
	else
	{
		if (argv[1][0] == 'm')
			env->f_type = MANDELBROT;
		else if (argv[1][0] == 'j')
			set_julia_env(env, argc, argv);
		else if (argv[1][0] == 't')
		{
			env->f_type = MULTIBROT;
			if (argc > 2)
				env->multibrot_n = ft_atoi(argv[2]);
			else
			{
				env->multibrot_n = 3;
				ft_printf("Multibrot power param was not passed, \
					set to 3 by default\n");
			}
		}
		else
			abort_illegal_args(env);
	}
}

void	set_zoom(t_fractol *env)
{
	env->zoom = (t_zoom *)malloc(sizeof(t_zoom));
	env->zoom->real_center = 0;
	env->zoom->imaginary_center = 0;
	env->zoom->factor = 1;
}

void	init_color(t_fractol *env)
{
	env->color_scale = (t_color *)malloc(sizeof(t_color));
	env->color_scale->red = 200;
	env->color_scale->green = 150;
	env->color_scale->blue = 198;
	env->color_scale->transparency = 255;
}

t_fractol	*init_env(int argc, char **argv)
{
	t_fractol	*env;
	int			i;

	env = (t_fractol *)malloc(sizeof(t_fractol));
	set_env_fractol_mode(env, argc, argv);
	set_env_boundaries(env);
	env->estimator_max = 100;
	env->width = 1400;
	env->height = 800;
	env->radius = 3;
	env->shift_val = 0.04;
	env->border = (int **)malloc(env->height * sizeof(int *));
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
