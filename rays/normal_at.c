/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal_at.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:55:45 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/24 13:05:17 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../matrix/rt_matrix.h"
#include "../tuples/tuples.h"
#include "../ptr_management/assign_free.h"
#include <stdlib.h>

static double	*world_norm(double **inverse, double *objv)
{
	double	*worldn;
	double	**transpose;

	transpose = mtx_transpose(inverse);
	worldn = mtx_x_tuple(transpose, objv);
	mtx_free(transpose, 4);
	free(objv);
	return (worldn);
}

double	*normal_at(t_shape *shp, double *world_p)
{
	double	*normalv;
	double	*local_p;
	double	**temp;

	temp = mtx_inversion(shp->transform);
	local_p = mtx_x_tuple(temp, world_p);
	if (shp->type == 's')
		normalv = ft_callswp_t2(local_p, point(0, 0, 0), tuple_sub);
	else if (shp->type == 'p')
		normalv = vector(0, 1, 0);
	else
		normalv = cylinder_normal_at(shp, local_p);
	if (shp->type != 's')
		free(local_p);
	normalv = world_norm(temp, normalv);
	normalv[3] = 0;
	normalv = ft_callswp_t1(normalv, vector_normalize);
	mtx_free(temp, 4);
	return (normalv);
}
