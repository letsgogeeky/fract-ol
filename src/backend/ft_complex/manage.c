/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:20:22 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/08 17:20:22 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backend.h"

void	set_complex(t_complex *point, double real, double imaginary)
{
	point->real = real;
	point->imag = imaginary;
}

t_complex	*complex_copy(t_complex *original)
{
	t_complex	*copied;

	copied = (t_complex *)malloc(sizeof(t_complex *));
	copied->real = original->real;
	copied->imag = original->imag;
	return (copied);
}
