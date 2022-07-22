/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shade_hit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:58:59 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 14:49:33 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../color/color.h"
#include "scene.h"
#include <stdlib.h>

static double	*calculate_color(double *mat_col, double *amb_col,
								double shading)
{
	double	*final_color;

	final_color = color(mat_col[0], mat_col[1], mat_col[2]);
	final_color[0] *= shading;
	final_color[0] += amb_col[0];
	final_color[1] *= shading;
	final_color[1] += amb_col[1];
	final_color[2] *= shading;
	final_color[2] += amb_col[2];
	free(amb_col);
	return (final_color);
}

static double	*ambient(double *obj_rgb, double *amb_rgb, double amb_cof)
{
	double	*final_amb;

	final_amb = color(0, 0, 0);
	final_amb[0] = obj_rgb[0] * amb_rgb[0] * amb_cof;
	final_amb[1] = obj_rgb[1] * amb_rgb[1] * amb_cof;
	final_amb[2] = obj_rgb[2] * amb_rgb[2] * amb_cof;
	return (final_amb);
}

double	*shade_hit(t_world *w, t_compute *comp)
{
	double		shading;
	double		*amb_col;
	t_material	*mat;

	mat = comp->shp->material;
	comp->shadowed = is_shadowed(w, comp->over_p);
	comp->obj_col = color_mult(mat->color, w->light->intensity);
	shading = lighting(mat, w->light, comp->p, comp);
	amb_col = ambient(mat->color, w->amb_rgb, w->amb);
	return (calculate_color(mat->color, amb_col, shading));
}
