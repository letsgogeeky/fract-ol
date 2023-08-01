#include "frontend.h"

void	control_details(mlx_key_data_t key, t_fractol *env)
{
	if (key.modifier != MLX_CONTROL)
			env->estimator_max += 5;
	else if (env->estimator_max > 5)
			env->estimator_max -= 5;
    env->should_draw = true;
}
