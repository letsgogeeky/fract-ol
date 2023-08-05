/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:29:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/05 23:29:51 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

void	control_red(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL && env->color_scale->red < 255)
		env->color_scale->red += 10;
	else if (env->color_scale->red > 0)
			env->color_scale->red -= 10;
}

void	control_green(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL && env->color_scale->green < 255)
			env->color_scale->green += 10;
	else if (env->color_scale->green > 0)
			env->color_scale->green -= 10;
}

void	control_blue(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL && env->color_scale->blue < 255)
			env->color_scale->blue += 10;
	else if (env->color_scale->blue > 0)
			env->color_scale->blue -= 10;
}

void	control_transparency(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL && env->color_scale->transparency < 255)
			env->color_scale->transparency += 10;
	else if (env->color_scale->transparency > 0)
			env->color_scale->transparency -= 10;
}
