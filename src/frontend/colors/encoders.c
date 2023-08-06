#include "frontend.h"

int get_rgba(int red, int green, int blue, int alpha)
{
    return (red << 24 | green << 16 | blue << 8 | alpha);
}

void smash_pixel(int x, int y, int32_t estimator, t_fractol *env)
{
	int color;

	color = 0x000000FF;
	if (estimator != env->estimator_max)
	{
		color = get_rgba((estimator * 7) % env->color_scale->red, \
			((estimator * 13) % env->color_scale->green), \
			(estimator * 31) % env->color_scale->blue,\
			env->color_scale->transparency);
	}
	env->border[y][x] = color;
	mlx_put_pixel(env->current_frame, x, y, color);
}
