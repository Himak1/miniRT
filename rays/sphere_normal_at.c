/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_normal_at.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:38:34 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:48:49 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../tuples/tuples.h"
#include "../ptr_management/assign_free.h"
#include "../matrix/rt_matrix.h"

double	*sphere_normal_at(t_shape *s, double *world_p)
{
	double	*obj_p;
	double	*obj_norm;
	double	**temp;

	temp = mtx_inversion(s->transform);
	obj_p = mtx_x_tuple(temp, world_p);
	obj_norm = ft_callswp_t2(obj_p, point(0, 0, 0), tuple_sub);
	mtx_free(temp, 4);
	return (obj_norm);
}
