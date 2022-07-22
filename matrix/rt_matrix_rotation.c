/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_rotation.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:49:58 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/25 15:24:42 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rt_matrix.h"
#include "../tuples/tuples.h"
#include "../ptr_management/assign_free.h"
#include <stdlib.h>
#include <math.h>

static void	angle_axis(double *xyz, double **axis, double *angle)
{
	double	*vec1;
	double	*vec2;

	vec1 = vector(0, 1, 0);
	vec2 = vector(xyz[0], xyz[1], xyz[2]);
	vec1 = ft_callswp_t1(vec1, vector_normalize);
	vec2 = ft_callswp_t1(vec2, vector_normalize);
	*angle = acos(dot_product(vec1, vec2));
	*axis = cross_product(vec1, vec2);
	free(vec1);
	free(vec2);
}

static void	assign_matrix(double **m, double *v, double *cs)
{
	double	v2[3];

	v2[0] = v[0] * v[0];
	v2[1] = v[1] * v[1];
	v2[2] = v[2] * v[2];
	m[0][0] = cs[0] + v2[0] * (1 - cs[0]);
	m[0][1] = v[0] * v[1] * (1 - cs[0]) - v[2] * cs[1];
	m[0][2] = v[0] * v[2] * (1 - cs[0]) + v[1] * cs[1];
	m[0][3] = 0;
	m[1][0] = v[1] * v[0] * (1 - cs[0]) + v[2] * cs[1];
	m[1][1] = cs[0] + v2[1] * (1 - cs[0]);
	m[1][2] = v[1] * v[2] * (1 - cs[0]) - v[0] * cs[1];
	m[1][3] = 0;
	m[2][0] = v[2] * v[0] * (1 - cs[0]) - v[1] * cs[1];
	m[2][1] = v[2] * v[1] * (1 - cs[0]) + v[0] * cs[1];
	m[2][2] = cs[0] + v2[2] * (1 - cs[0]);
	m[2][3] = 0;
	m[3][3] = 1;
}

double	**mtx_rotation(double *xyz)
{
	double	angle;
	double	*axis;
	double	cs[2];
	double	**matrix;

	angle = 0;
	axis = 0;
	angle_axis(xyz, &axis, &angle);
	cs[0] = cos(angle);
	cs[1] = sin(angle);
	matrix = mtx_malloc(4);
	assign_matrix(matrix, axis, cs);
	free(axis);
	return (matrix);
}
