/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tuple_product.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:52:00 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:52:01 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_error_exit.h"
#include <stdlib.h>

double	dot_product(double *vector1, double *vector2)
{
	double	ret;

	ret = vector1[0] * vector2[0];
	ret += vector1[1] * vector2[1];
	ret += vector1[2] * vector2[2];
	ret += vector1[3] * vector2[3];
	return (ret);
}

double	*cross_product(double *vector1, double *vector2)
{
	double	*ret;

	ret = malloc(4 * sizeof(double));
	if (ret == NULL)
		error_exit(MALLOC_F);
	ret[0] = (vector1[1] * vector2[2]) - (vector1[2] * vector2[1]);
	ret[1] = (vector1[2] * vector2[0]) - (vector1[0] * vector2[2]);
	ret[2] = (vector1[0] * vector2[1]) - (vector1[1] * vector2[0]);
	ret[3] = 0;
	return (ret);
}
