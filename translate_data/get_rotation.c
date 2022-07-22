/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_rotation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:33:18 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 16:42:55 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include "../matrix/rt_matrix.h"
#include "../ptr_management/assign_free.h"

void	get_rotation(double *vec_xyz, t_shape *shp)
{
	double	**rot;

	rot = mtx_rotation(vec_xyz);
	rot = ft_callswp_m1(rot, mtx_transpose);
	shp->transform = ft_callswp_m2(rot, shp->transform, mtx_multiply);
}
