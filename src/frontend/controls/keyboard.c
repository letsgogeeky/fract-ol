#include "frontend.h"

void ft_key_hook(mlx_key_data_t key, void * param)
{
	printf("%p\n", param);
	if(key.key == MLX_KEY_SPACE && mlx_is_key_down(param, MLX_KEY_SPACE))
	{
		puts("The SPACE key was pressed!");
	}
}