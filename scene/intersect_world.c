/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_world.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:33:39 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 20:56:31 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "../rt_error_exit.h"
#include <stdlib.h>

t_intersect	**intersect_world(t_world *w, t_ray *r)
{
	t_intersect	**array;
	int			i;
	int			j;

	i = 0;
	j = 0;
	array = malloc((w->num_shp * 2 + 1) * sizeof(t_intersect *));
	if (!array)
		error_exit(MALLOC_F);
	while (i < w->num_shp)
	{
		j = intersect(array, j, w->shp[i], r);
		i++;
	}
	array[j] = NULL;
	return (array);
}
