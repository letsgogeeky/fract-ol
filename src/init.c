/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:28:58 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 11:13:51 by ramoussa         ###   ########.fr       */
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

void	show_program_options()
{
	ft_printf("Please specify a Fractal of the following:\n");
	ft_printf("1. `mandelbrot`\n");
	ft_printf("2. `julia` <REAL C> <IMAGINARY C>  (if left blank, default values is applied.\n");
	ft_printf("3. `multibrot <POWER (default = 3)>` a dynamic fractal of mandelbrot family.\n");
}

static void set_env_fractol_mode(t_fractol *env, int argc, char **argv)
{
    if (argc < 2)
	{
		
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
			if (argc >= 4)
			{
				env->julia_c.real = get_double(argv[2]);
				env->julia_c.imag = get_double(argv[3]);
			}
			else
			{
				env->julia_c.real = 0;
				env->julia_c.imag = 0.8;
				ft_printf("You did not specify C for Julia, setting default values...\n");
			}
		}
		else if (is_equal_str(argv[1], "multibrot"))
		{
			env->f_type = MULTIBROT;
			env->name = "MULTIBROT Fractal";
			if (argc > 2)
				env->multibrot_n = ft_atoi(argv[2]);
			else
			{
				env->multibrot_n = 3;
				ft_printf("Multibrot power param was not passed, set to 3 by default\n");
			}
		}
		else
		{
			ft_printf("UNKNOWN FRACTAL PASSED AS PARAM...!\n");
			show_program_options();
			free(env);
			exit(0);
		}
	}
}

void        set_env_boundaries(t_fractol *env)
{
	env->real_min = -2.5;
	env->real_max = 2.5;
	env->imaginary_max = 1.5;
	env->imaginary_min = -1.5;
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

    env->color_scale->red = 200;
    env->color_scale->green = 150;
    env->color_scale->blue = 255;
    env->color_scale->transparency = 255;
}

t_fractol   *init_env(int argc, char **argv)
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
