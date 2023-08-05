/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:41:45 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/05 22:34:45 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"

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

void	complex_pow_3(t_complex *complex)
{
	double	original_real;

	original_real = complex->real;
	complex->real = pow(original_real, 3) - (3 * pow(complex->imag, 3));
	complex->imag = 3 * original_real * original_real * complex->imag - pow(complex->imag, 3);
}

void	complex_multiply_scalar(t_complex *complex, int scalar)
{
	complex->real = complex->real * scalar;
	complex->imag = complex->imag * scalar;
}

//(a + bi) / (c + di) = ((a*c + b*d) + (b*c - a*d)i) / (c^2 + d^2)
t_complex	*complex_divide(t_complex *numerator, t_complex	*denominator)
{
	t_complex	*result;
	double		denominator_squared;
	result = (t_complex *)malloc(sizeof(t_complex));

	denominator_squared = denominator->real * denominator->real + denominator->imag * denominator->imag;
	result->real = numerator->real * denominator->real + numerator->imag * denominator->imag;
	result->imag = numerator->imag * denominator->real + numerator->real * denominator->imag;
	free(numerator);
	free(denominator);
	return (result);
}

void	complex_subtract(t_complex *c1, t_complex *c2)
{
	c1->real = c1->real - c2->real;
	c1->imag = c1->imag - c2->imag;
}

t_complex	*complex_subtract_immutable(t_complex *c1, t_complex c2)
{
	t_complex	*result;

	result = (t_complex *)malloc(sizeof(t_complex));
	result->real = c1->real - c2.real;
	result->imag = c1->imag - c2.imag;
	return (result);
}

// void	complex_pow(t_complex *complex, uint8_t pow)
// {
// 	t_complex *cpy;

// 	cpy = complex_copy(complex);
// 	while (pow > 0)
// 	{
// 		complex_multiply()
// 	}
// }
