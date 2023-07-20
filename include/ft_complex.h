#ifndef COMPLEX_H
# define COMPLEX_H

#include <math.h>
#include <stdlib.h>

typedef struct s_complex
{
    double real;
    double imag;
}   t_complex;

void        complex_multiply(t_complex *complex);
void        complex_add(t_complex *original, const t_complex *c);
t_complex   *complex_copy(t_complex *original);
void        print_complex(t_complex *complex);

#endif