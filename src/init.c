#include "backend.h"
#include "frontend.h"

int	ft_strlen(const char *c)
{
	int	size;

	size = 0;
	while (c[size] != '\0')
	{
		size++;
	}
	return (size);
}

int is_equal_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (!s1 && !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\n')
		i++;
	if (i < ft_strlen(s1))
		return (0);
	return (1);
}

static void set_env_fractol_mode(t_fractol *env, int argc, char **argv)
{
    if (argc < 2)
	{
		env->f_type = MANDELBROT;
		env->name = "Mandelbrot Fractol";
	}
	else
	{
		if (is_equal_str(argv[1], "mandelbrot"))
		{
			env->f_type = MANDELBROT;
			env->name = "Mandelbrot Fractol";
		}
		else if (is_equal_str(argv[1], "julia"))
		{
			env->f_type = JULIA;
			env->name = "Julia Fractol";
		}
	}
}

void        set_env_boundaries(t_fractol *env)
{
    if (env->f_type == MANDELBROT)
    {
        env->real_min = -2.2;
        env->real_max = 1.2;
        env->imaginary_max = 1.2;
        env->imaginary_min = -1.2;
    }
    else if (env->f_type == JULIA)
    {
        env->real_min = -2;
        env->real_max = 1.8;
        env->imaginary_max = 1.3;
        env->imaginary_min = -1.5;
    }
}

void    set_zoom(t_fractol *env)
{
    env->zoom = (t_zoom *)malloc(sizeof(t_zoom));
    env->zoom->real_center = 0;
    env->zoom->imaginary_center = 0;
    env->zoom->factor = 1;
}

void    init_color(t_fractol *env)
{
    env->color_scale = (t_color *)malloc(sizeof(t_color));

    env->color_scale->red = 1;
    env->color_scale->green = 1;
    env->color_scale->blue = 1;
    env->color_scale->transparency = 1;
}

t_fractol   *init_env(int argc, char **argv)
{
    t_fractol *env;

    env = (t_fractol *)malloc(sizeof(t_fractol));
	set_env_fractol_mode(env, argc, argv);
    set_env_boundaries(env);
	env->estimator_max = 300;
	env->width = 1366;
	env->height = 960;
    env->radius = 30;
    set_zoom(env);
    env->pixel_size_x = (double)(env->real_max - env->real_min) / env->width;
    env->pixel_size_y = (double)(env->imaginary_max - env->imaginary_min) / env->height;
    init_color(env);
    return (env);
}
