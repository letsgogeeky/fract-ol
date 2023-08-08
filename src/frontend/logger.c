/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 05:49:17 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 18:53:20 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

void	show_program_options(void)
{
	ft_printf("\033[1m\033[36m");
	ft_printf("Please specify a Fractal of the following:\n");
	ft_printf("1. `m` to render Mandelbrot.\n");
	ft_printf("2. `j <REAL C> <IMAGINARY C>` \
		to render Julia (if left blank, default values is applied.\n");
	ft_printf("3. `t <POWER (default = 3)>` \
		to render Multibrot: a dynamic fractal of mandelbrot family.\n");
	ft_printf("\033[1m\033[32m");
	ft_printf("Press H for Help and Options\n");
}

static void	print_env(t_fractol *env)
{
	ft_printf("\033[1m\033[32m");
	ft_printf("Width on env = %d\n", env->width);
	ft_printf("env estimator = %d\n", env->estimator_max);
	ft_printf("Pizel Size: %f\n", env->pixel_size);
	ft_printf("Real Min: %f || Real Max: %f\n", env->real_min, env->real_max);
	ft_printf("Imaginary Min: %f || Imaginary Max: %f\n", \
		env->imaginary_min, env->imaginary_max);
	ft_printf("Zoom factor: %f\n", env->zoom->factor);
}

void	show_help(t_fractol *env)
{
	ft_printf("\033[36m");
	ft_printf("Key bindings:\n");
	ft_printf("R (increase) or CNTRL + R (decrease) :: \
		Controls Red shift\n");
	ft_printf("G (increase) or CNTRL + G (decrease) :: \
		Controls Green shift\n");
	ft_printf("B (increase) or CNTRL + B (decrease) :: \
		Controls Blue shift\n");
	ft_printf("A (increase) or CNTRL + A (decrease) :: \
		Controls Transparency level\n");
	ft_printf("---------------------------------------\n");
	ft_printf("D (increase) or CNTRL + D (decrease) :: \
		Controls level of Details in the fractal\n");
	ft_printf("0 :: (zero) Apply border finding algorithm\n");
	ft_printf("---------------------------------------\n");
	ft_printf("Use the 4 arrow keys to explore \
		left, right, up, & down the complex plane\n");
	ft_printf("---------------------------------------\n");
	print_env(env);
	show_program_options();
}
