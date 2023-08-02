#include "backend.h"

void        set_complex(t_complex *point, double real, double imaginary)
{
    point->real = real;
    point->imag = imaginary;
}

t_complex	*complex_copy(t_complex *original)
{
	t_complex *copied;

	copied = (t_complex *)malloc(sizeof(t_complex *));
	copied->real = original->real;
	copied->imag = original->imag;

	return(copied); 
}
