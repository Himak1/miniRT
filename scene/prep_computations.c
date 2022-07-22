/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prep_computations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:40:56 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/26 17:34:27 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_error_exit.h"
#include "../tuples/tuples.h"
#include "../ptr_management/assign_free.h"
#include "scene.h"
#include <stdlib.h>

static void	check_inside(t_compute *compute)
{
	if (dot_product(compute->eyev, compute->normalv) < 0)
	{
		compute->normalv = ft_callswp_t1(compute->normalv, tuple_negate);
		compute->inside = 1;
	}
	else
		compute->inside = 0;
}

void	prep_compute(t_intersect *i, t_ray *r, t_compute *compute)
{
	double	*temp;

	compute->t = i->t;
	compute->shp = i->obj;
	temp = tuple_mult_alloc(r->direction, i->t);
	compute->p = tuple_add(r->origin, temp);
	compute->eyev = tuple_negate(r->direction);
	compute->normalv = normal_at(compute->shp, compute->p);
	free(temp);
	check_inside(compute);
	temp = tuple_mult_alloc(compute->normalv, EPSILON);
	compute->over_p = tuple_add(compute->p, temp);
	free(temp);
}
