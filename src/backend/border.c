/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:56:01 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 18:36:58 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"

void	set_if_border(t_fractol *env, int x, int y)
{
	if (x - 1 < 0 || x + 1 >= env->width || y - 1 < 0 || y + 1 >= env->height)
		return ;
	if (env->border[y][x + 1] != 0x000000FF)
		env->border[y][x + 1] = 1;
	else if (env->border[y][x - 1] != 0x000000FF)
		env->border[y][x - 1] = 1;
	else if (env->border[y + 1][x] != 0x000000FF)
		env->border[y + 1][x] = 1;
	else if (env->border[y - 1][x] != 0x000000FF)
		env->border[y - 1][x] = 1;
}

void	set_border_matrix(t_fractol *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			if (env->border[y][x] == BLACK)
			{
				set_if_border(env, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
