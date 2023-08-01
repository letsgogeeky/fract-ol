#include "backend.h"

t_complex	*complex_copy(t_complex *original)
{
	t_complex *copied;

	copied = (t_complex *)malloc(sizeof(t_complex *));
	copied->real = original->real;
	copied->imag = original->imag;

	return(copied); 
}

void    print_boundaries(t_fractol *env)
{
    printf("Real Min: %f        || Real Max: %f\n", env->real_min, env->real_max);
    printf("Imaginary Min: %f   || Imaginary Max: %f\n", env->imaginary_min, env->imaginary_max);
    printf("Pixel Size: %f\n", env->pixel_size);
	printf("Zoom factor: %f\n", env->zoom->factor);
}

// void	print_complex(t_complex *complex)
// {
// 	puts("complex->real = %f || complex->imaginary = %f\n", complex->real, complex->imag);
// }
