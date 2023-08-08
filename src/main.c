/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:29:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 18:37:24 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

static void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	register_hooks(t_fractol *env)
{
	mlx_key_hook(env->mlx, ft_key_hook, env);
	mlx_scroll_hook(env->mlx, mouse_scroll_hook, env);
	mlx_cursor_hook(env->mlx, mouse_cursor_hook, env);
	mlx_resize_hook(env->mlx, ft_window_resize_hook, env);
	mlx_close_hook(env->mlx, window_exit_hook, env);
}

int	main(int argc, char **argv)
{
	t_fractol	*env;

	env = init_env(argc, argv);
	env->mlx = mlx_init(env->width, env->height, \
				"Fractals (Mandelbrot, Julia, & Multibrot)", \
				false);
	if (!env->mlx)
		ft_error();
	env->current_frame = mlx_new_image(env->mlx, env->width, env->height);
	if (!env->current_frame || \
			(mlx_image_to_window(env->mlx, env->current_frame, 0, 0) < 0))
		ft_error();
	show_help(env);
	mlx_loop_hook(env->mlx, (t_fractol_loop_func)compute_frame, env);
	register_hooks(env);
	mlx_loop(env->mlx);
	return (EXIT_SUCCESS);
}
