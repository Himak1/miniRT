/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_intersect.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:37:22 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:37:23 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../rt_error_exit.h"
#include <stdlib.h>
#include <math.h>

static double	check_caps(t_ray *ry, double t)
{
	double	x;
	double	z;
	double	ret;

	x = ry->origin[0] + (t * ry->direction[0]);
	z = ry->origin[2] + (t * ry->direction[2]);
	ret = sqr(x) + sqr(z);
	return (ret);
}

static int	assign_base(t_intersect **array, int j, t_shape *shp, double t)
{
	array[j] = malloc(1 * sizeof(t_intersect));
	if (!array[j])
		error_exit(MALLOC_F);
	array[j]->obj = shp;
	array[j]->t = t;
	return (j + 1);
}

static int	caps(t_intersect **array, int j, t_shape *shp, t_ray *ry)
{
	double	t;
	t_cylin	*temp;

	temp = shp->shp_data;
	if (equal(0, ry->direction[1]) == 1)
		return (j);
	t = (temp->min - ry->origin[1]) / ry->direction[1];
	if (check_caps(ry, t) <= 1)
		j = assign_base(array, j, shp, t);
	t = (temp->max - ry->origin[1]) / ry->direction[1];
	if (check_caps(ry, t) <= 1)
		j = assign_base(array, j, shp, t);
	return (j);
}

static int	check_base(t_cylin *cylin, double y)
{
	if (cylin->min < y && y < cylin->max)
		return (1);
	else
		return (0);
}

int	cylinder_intersect(t_intersect **array, int j, t_shape *shp, t_ray *ry)
{
	double	abc[3];
	double	t[2];
	double	y[2];
	double	disc;

	abc[0] = sqr(ry->direction[0]) + sqr(ry->direction[2]);
	if (abc[0] == 0)
		return (caps(array, j, shp, ry));
	abc[1] = 2 * ry->origin[0] * ry->direction[0]
		+ 2 * ry->origin[2] * ry->direction[2];
	abc[2] = sqr(ry->origin[0]) + sqr(ry->origin[2]) - 1;
	disc = sqr(abc[1]) - 4 * abc[0] * abc[2];
	if (disc < 0)
		return (j);
	t[0] = (-abc[1] - sqrt(disc)) / (2 * abc[0]);
	t[1] = (-abc[1] + sqrt(disc)) / (2 * abc[0]);
	y[0] = ry->origin[1] + (t[0] * ry->direction[1]);
	y[1] = ry->origin[1] + (t[1] * ry->direction[1]);
	if (check_base(shp->shp_data, y[0]) == 1)
		j = assign_base(array, j, shp, t[0]);
	if (check_base(shp->shp_data, y[1]) == 1)
		j = assign_base(array, j, shp, t[1]);
	j = caps(array, j, shp, ry);
	return (j);
}
