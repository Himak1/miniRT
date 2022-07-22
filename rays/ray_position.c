/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_position.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:49:37 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:49:38 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../tuples/tuples.h"

double	*ray_position(t_ray *ray, double time)
{
	double	*ret;

	ray->direction[0] *= time;
	ray->direction[1] *= time;
	ray->direction[2] *= time;
	ret = tuple_add(ray->origin, ray->direction);
	return (ret);
}
