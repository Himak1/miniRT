/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_intersect.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:48:53 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:48:57 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../rt_error_exit.h"
#include "../tuples/tuples.h"
#include <math.h>
#include <stdlib.h>

/*
** calculates the t values and assigns them to an array
*/

static void	intersect_assign(t_intersect **arr, int j, t_ray *r)
{
	double	dots[3];
	double	discriminant;
	double	*sp_to_ry;
	double	*sp_point;

	sp_point = point(0, 0, 0);
	sp_to_ry = tuple_sub(r->origin, sp_point);
	dots[0] = dot_product(r->direction, r->direction);
	dots[1] = 2 * dot_product(r->direction, sp_to_ry);
	dots[2] = dot_product(sp_to_ry, sp_to_ry) - 1;
	free(sp_to_ry);
	free(sp_point);
	discriminant = dots[1] * dots[1] - 4 * dots[0] * dots[2];
	if (discriminant <= 0)
	{
		arr[j]->t = NAN;
		arr[j + 1]->t = NAN;
		return ;
	}
	arr[j]->t = (-dots[1] - sqrt(discriminant)) / (2 * dots[0]);
	arr[j + 1]->t = (-dots[1] + sqrt(discriminant)) / (2 * dots[0]);
}

int	sp_intersect(t_intersect **arr, int j, t_shape *s, t_ray *r)
{
	arr[j] = malloc(1 * sizeof(t_intersect));
	arr[j + 1] = malloc(1 * sizeof(t_intersect));
	if (!arr[j] || !arr[j + 1])
		error_exit(MALLOC_F);
	intersect_assign(arr, j, r);
	arr[j]->obj = s;
	arr[j + 1]->obj = s;
	return (j + 2);
}
