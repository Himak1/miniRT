/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_transform.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:49:20 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:49:21 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../matrix/rt_matrix.h"
#include "../rt_error_exit.h"
#include <stdlib.h>

t_ray	*ray_transform(t_ray *r, double **trans_matrix)
{
	t_ray	*ret;

	ret = malloc(sizeof(t_ray));
	if (ret == NULL)
		error_exit(MALLOC_F);
	ret->origin = mtx_x_tuple(trans_matrix, r->origin);
	ret->direction = mtx_x_tuple(trans_matrix, r->direction);
	return (ret);
}
