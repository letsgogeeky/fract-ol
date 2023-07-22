#include "frontend.h"

void ft_pixel(void *img, int x, int y, int32_t estimator, t_fractol *env)
{
	if (estimator == env->estimator_max)
	{
		mlx_put_pixel(img, x, y, 0x000000FF);
	}
	else
	{
		mlx_put_pixel(img, x, y, 0xF0AA00FF * estimator);
	}
}