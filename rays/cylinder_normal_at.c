/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_normal_at.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:37:33 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:37:33 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../tuples/tuples.h"
#include <math.h>

double	*cylinder_normal_at(t_shape *shp, double *world_p)
{
	double	dist;
	t_cylin	*data;

	data = shp->shp_data;
	dist = sqr(world_p[0]) + sqr(world_p[2]);
	if (dist < 1 && world_p[1] >= data->max - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && world_p[1] <= data->min + EPSILON)
		return (vector(0, -1, 0));
	else
		return (vector(world_p[0], 0, world_p[2]));
}
