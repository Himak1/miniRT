/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_ini.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:49:40 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:49:41 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../rt_error_exit.h"
#include <stdlib.h>

t_ray	*ray(double *point, double *vector)
{
	t_ray	*ret;

	ret = malloc(sizeof(t_ray));
	if (!ret)
		error_exit(MALLOC_F);
	ret->origin = point;
	ret->direction = vector;
	return (ret);
}
