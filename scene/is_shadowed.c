/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_shadowed.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:36:34 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/24 13:14:00 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>
#include "../tuples/tuples.h"
#include "../ptr_management/assign_free.h"

static int	parse_inters(t_world *w, t_ray *r, double distance)
{
	t_intersect	**inter_arr;
	t_intersect	*hit_i;

	inter_arr = intersect_world(w, r);
	hit_i = hit(inter_arr);
	if (hit_i != NULL && hit_i->t < distance + 0.00001)
	{
		ray_free(r);
		intersect_free(inter_arr);
		return (1);
	}
	ray_free(r);
	intersect_free(inter_arr);
	return (0);
}

int	is_shadowed(t_world *world, double *check_point)
{
	double	*vect;
	double	distance;
	t_ray	*ry;

	vect = tuple_sub(world->light->position, check_point);
	distance = vector_magnitude(vect);
	vect = ft_callswp_t1(vect, vector_normalize);
	ry = ray(check_point, vect);
	return (parse_inters(world, ry, distance));
}
