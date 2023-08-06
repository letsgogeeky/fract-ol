#include "frontend.h"

void draw_multibrot(t_fractol *env)
{
	int x;
	int y;
	int n;
	t_complex *z;
	t_complex *c;

	z = (t_complex *)malloc(sizeof(t_complex*));
	c = (t_complex *)malloc(sizeof(t_complex*));
	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			n = compute_multibrot_pixel(env, z, c, x, y, 10);
			smash_pixel(x, y, n, env);
			x++;
		}
		x = 0;
		y++;
	}
	free(z);
	free(c);
}