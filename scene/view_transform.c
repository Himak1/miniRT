/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_transform.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:59:29 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:02:05 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_error_exit.h"
#include "../matrix/rt_matrix.h"
#include "../rays/rays.h"
#include "../tuples/tuples.h"
#include "../ptr_management/assign_free.h"
#include <stdlib.h>

static double	**translate_view(double **view, double *pos)
{
	double	**translate;
	double	**final;

	translate = mtx_translation(pos[0], pos[1], pos[2]);
	final = mtx_multiply(view, translate);
	mtx_free(view, 4);
	mtx_free(translate, 4);
	return (final);
}

static int	gimbal_lock_fix(double **matrix, double *vec)
{
	if ((equal(0, vec[0]) && equal(0, vec[2])) && !equal(0, vec[1]))
	{
		matrix[0] = vector(1, 0, 0);
		return (1);
	}
	else
		return (0);
}

double	**view_transform(double *pos, double *direction)
{
	double	**matrix;
	double	*up;

	up = ft_callswp_t1(vector(0, 1, 0), vector_normalize);
	matrix = malloc(4 * sizeof(double *));
	if (!matrix)
		error_exit(MALLOC_F);
	matrix[2] = vector_normalize(direction);
	if (gimbal_lock_fix(matrix, direction) == 0)
		matrix[0] = cross_product(matrix[2], up);
	matrix[0] = ft_callswp_t1(matrix[0], vector_normalize);
	matrix[1] = cross_product(matrix[0], matrix[2]);
	matrix[3] = point(0, 0, 0);
	matrix[2] = ft_callswp_t1(matrix[2], tuple_negate);
	matrix = translate_view(matrix, pos);
	free(up);
	return (matrix);
}
