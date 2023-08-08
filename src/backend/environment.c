/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:58:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 18:56:20 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"

void	update_pixel_size(t_fractol *env)
{
	env->pixel_size = (double)(env->real_max - env->real_min) / env->width;
}

void	terminate_app(t_fractol *env)
{
	int	idx;

	idx = 0;
	while (idx < env->height)
	{
		free(env->border[idx]);
		idx++;
	}
	free(env->border);
	mlx_delete_image(env->mlx, env->current_frame);
	mlx_terminate(env->mlx);
	free(env);
	exit(0);
}

void	set_julia_env(t_fractol *env, int argc, char **argv)
{
	env->f_type = JULIA;
	if (argc >= 4)
	{
		env->julia_c.real = get_double(argv[2]);
		env->julia_c.imag = get_double(argv[3]);
	}
	else
	{
		env->julia_c.real = 0;
		env->julia_c.imag = 0.8;
		ft_printf("You did not specify C for Julia, \
			setting default values...\n");
	}
}

void	set_env_boundaries(t_fractol *env)
{
	env->real_min = -2.5;
	env->min.real = -2.5;
	env->real_max = 2.5;
	env->max.real = 2.5;
	env->imaginary_max = 1.5;
	env->max.imag = 1.5;
	env->imaginary_min = -1.5;
	env->min.imag = -1.5;
}
