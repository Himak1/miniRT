/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   global_intersect.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:58:16 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 19:58:16 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../matrix/rt_matrix.h"

int	intersect(t_intersect **array, int j, t_shape *shp, t_ray *ry)
{
	t_ray		*ray_trans;
	double		**shp_inverse;

	shp_inverse = mtx_inversion(shp->transform);
	ray_trans = ray_transform(ry, shp_inverse);
	if (shp->type == 's')
		j = sp_intersect(array, j, shp, ray_trans);
	else if (shp->type == 'p')
		j = plane_intersect(array, j, shp, ray_trans);
	else
		j = cylinder_intersect(array, j, shp, ray_trans);
	ray_free(ray_trans);
	mtx_free(shp_inverse, 4);
	return (j);
}
