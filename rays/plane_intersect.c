/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_intersect.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:50:23 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:50:24 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../tuples/tuples.h"
#include "../rt_error_exit.h"
#include <stdlib.h>
#include <math.h>

int	plane_intersect(t_intersect **arr, int j, t_shape *shp, t_ray *ry)
{
	arr[j] = malloc(1 * sizeof(t_intersect));
	if (!arr[j])
		error_exit(MALLOC_F);
	if (fabs(ry->direction[1]) < EPSILON)
		arr[j]->t = NAN;
	else
	{
		arr[j]->t = -ry->origin[1] / ry->direction[1];
	}
	arr[j]->obj = shp;
	j++;
	return (j);
}
