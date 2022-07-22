/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_at.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:31:43 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 20:56:37 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_error_exit.h"
#include "../color/color.h"
#include "scene.h"
#include <stdlib.h>

double	*color_at(t_world *w, t_ray *r)
{
	t_intersect	**inter_arr;
	t_compute	compute;
	t_intersect	*hit_i;
	double		*shade;

	inter_arr = intersect_world(w, r);
	hit_i = hit(inter_arr);
	if (hit_i == NULL)
	{
		intersect_free(inter_arr);
		return (color(0, 0, 0));
	}
	prep_compute(hit_i, r, &compute);
	shade = shade_hit(w, &compute);
	intersect_free(inter_arr);
	free(compute.p);
	free(compute.eyev);
	free(compute.normalv);
	return (shade);
}
