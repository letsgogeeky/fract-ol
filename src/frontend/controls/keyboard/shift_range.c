/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:30:00 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 18:18:58 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

void	go_left(t_fractol *env)
{
	double	range;

	range = env->real_max - env->real_min;
	env->real_min -= (range * env->shift_val);
	env->real_max -= (range * env->shift_val);
}

void	go_right(t_fractol *env)
{
	double	range;

	range = env->real_max - env->real_min;
	env->real_min += (range * env->shift_val);
	env->real_max += (range * env->shift_val);
}

void	go_up(t_fractol *env)
{
	double	range;

	range = env->imaginary_max - env->imaginary_min;
	env->imaginary_max += (range * env->shift_val);
	env->imaginary_min += (range * env->shift_val);
}

void	go_down(t_fractol *env)
{
	double	range;

	range = env->imaginary_max - env->imaginary_min;
	env->imaginary_max -= (range * env->shift_val);
	env->imaginary_min -= (range * env->shift_val);
}
