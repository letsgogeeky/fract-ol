#include "frontend.h"

void ft_window_resize_hook(int32_t width, int32_t height, void * param)
{
    printf("%p\n", param);
	printf("width: %d | height: %d\n", width, height);
}