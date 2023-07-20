#include "frontend.h"

void ft_scroll_hook(double delta_x, double delta_y, void * param)
{
    printf("%p\n", param);
	printf("delta x: %f | delta y: %f\n", delta_x, delta_y);
}
