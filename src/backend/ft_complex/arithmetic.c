/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:41:45 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 17:19:27 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"

void	complex_multiply(t_complex *complex)
{
	double	original_real;

	original_real = complex->real;
	complex->real = (original_real * original_real) - \
			(complex->imag * complex->imag);
	complex->imag = (original_real * complex->imag) + \
			(complex->imag * original_real);
}

t_complex	complex_multiply_immutable(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = (a.real * b.real) - (a.imag * b.imag);
	result.imag = (a.real * b.imag) + (a.imag * b.real);
	return (result);
}

void	complex_add(t_complex *original, const t_complex *c)
{
	original->real += c->real;
	original->imag += c->imag;
}

t_complex	complex_add_immutable(t_complex original, t_complex c)
{
	t_complex	result;

	result.real = original.real + c.real;
	result.imag = original.imag + c.imag;
	return (result);
}
