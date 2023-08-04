#include "frontend.h"

static void print_env(t_fractol *env)
{
	ft_printf("Width on env = %d\n", env->width);
	ft_printf("env estimator = %d\n", env->estimator_max);
	ft_printf("pixel size real: %f\n", env->pixel_size);
	ft_printf("Real Min: %f || Real Max: %f\n", env->real_min, env->real_max);
    ft_printf("Imaginary Min: %f || Imaginary Max: %f\n", env->imaginary_min, env->imaginary_max);
	ft_printf("Zoom factor: %f\n", env->zoom->factor);
}

void	show_help(t_fractol *env)
{
	ft_printf("Key bindings:\n");
	ft_printf("R (increase) or CNTRL + R (decrease) :: Controls Red shift\n");
	ft_printf("G (increase) or CNTRL + G (decrease) :: Controls Green shift\n");
	ft_printf("B (increase) or CNTRL + B (decrease) :: Controls Blue shift\n");
	ft_printf("A (increase) or CNTRL + A (decrease) :: Controls Transparency level\n");
	ft_printf("---------------------------------------\n");
	ft_printf("D (increase) or CNTRL + D (decrease) :: Controls level of Details in the fractal\n");
	ft_printf("0 :: (zero) Apply border finding algorithm\n");
	ft_printf("---------------------------------------\n");
	print_env(env);
}