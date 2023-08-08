/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:45:46 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 17:21:23 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

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

void	compute_frame(t_fractol *env)
{
	if (env->should_draw == false)
		return ;
	if (env->f_type == JULIA)
		draw_julia(env);
	else if (env->f_type == MANDELBROT)
		draw_mandelbrot(env);
	else if (env->f_type == MULTIBROT)
		draw_multibrot(env);
	env->should_draw = false;
}
