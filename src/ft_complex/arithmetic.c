#include "ft_complex.h"

void   complex_multiply(t_complex *complex)
{
    double   original_real;

	original_real = complex->real;
    complex->real = (original_real * original_real) - (complex->imag * complex->imag);
    complex->imag = (original_real * complex->imag) + (complex->imag * original_real);
}

void	complex_add(t_complex *original, const t_complex* c)
{
	original->real += c->real;
	original->imag += c->imag;
}
