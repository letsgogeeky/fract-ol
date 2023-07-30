#include "frontend.h"

void	go_left(t_fractol *env)
{
	double range;

    range = env->real_max - env->real_min;
    env->real_min -= (range * 0.1);
    env->real_max -= (range * 0.1);		
}
void	go_right(t_fractol *env)
{
	double range;

    range = env->real_max - env->real_min;
    env->real_min += (range * 0.1);
    env->real_max += (range * 0.1);
		
}
void	go_up(t_fractol *env)
{
	double range;

    range = env->imaginary_max - env->imaginary_min;
    env->imaginary_max += (range * 0.1);
    env->imaginary_min += (range * 0.1);		
}
void	go_down(t_fractol *env)
{
	double range;

    range = env->imaginary_max - env->imaginary_min;
    env->imaginary_max -= (range * 0.1);
    env->imaginary_min -= (range * 0.1);
}
