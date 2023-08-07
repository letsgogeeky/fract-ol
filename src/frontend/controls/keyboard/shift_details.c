/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_details.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:29:56 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/05 23:29:57 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

void	control_details(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL)
			env->estimator_max += 5;
	else if (env->estimator_max > 5)
			env->estimator_max -= 5;
    env->should_draw = true;
}
