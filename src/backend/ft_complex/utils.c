#include "backend.h"

t_complex	*complex_copy(t_complex *original)
{
	t_complex *copied;

	copied = (t_complex *)malloc(sizeof(t_complex *));
	copied->real = original->real;
	copied->imag = original->imag;

	return(copied); 
}

// void	print_complex(t_complex *complex)
// {
// 	puts("complex->real = %f || complex->imaginary = %f\n", complex->real, complex->imag);
// }
