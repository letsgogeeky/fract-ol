/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:30:07 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 11:11:33 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

void ft_window_resize_hook(int32_t width, int32_t height, void * param)
{
    t_fractol *env;
    env = (t_fractol *)param;

    env->width = width;
    env->height = height;
	mlx_delete_image(env->mlx, env->current_frame);
	mlx_image_t* img = mlx_new_image(env->mlx, env->width, env->height);
	if (!img || (mlx_image_to_window(env->mlx, img, 0, 0) < 0))
		return ;
	env->current_frame = img;
	env->should_draw = true;
}

void window_exit_hook(void *param)
{
    t_fractol *env;

    env = (t_fractol *)param;
    terminate_app(env);
}