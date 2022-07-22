/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:57:27 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 14:04:43 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../tuples/tuples.h"
#include "../rt_error_exit.h"
#include "../ptr_management/assign_free.h"
#include "../color/color.h"
#include <stdlib.h>
#include <math.h>

static double	add_up(double *color, double val)
{
	int		i;
	double	temp;

	i = 0;
	temp = 0.0;
	while (i < 3)
	{
		temp += val * color[i];
		i++;
	}
	return (val);
}

static void	specular_set(t_material *mat, t_plight *light,
						t_compute *comp, double reflect_dot_eye)
{
	double	factor;

	factor = pow(reflect_dot_eye, mat->shininess);
	comp->ads[2] = add_up(light->intensity, mat->specular * factor);
}

static void	diffuse_set(t_material *mat, t_plight *light, t_compute *comp)
{
	double	lt_dot_norm;
	double	*reflectv;
	double	reflect_dot_eye;
	double	*temp;

	lt_dot_norm = dot_product(comp->lightv, comp->normalv);
	if (lt_dot_norm < 0)
	{
		comp->ads[1] = 0;
		comp->ads[2] = 0;
	}
	else
	{
		comp->ads[1] = add_up(comp->obj_col, mat->diffuse * lt_dot_norm);
		temp = tuple_negate(comp->lightv);
		reflectv = reflect(temp, comp->normalv);
		reflect_dot_eye = dot_product(reflectv, comp->eyev);
		if (reflect_dot_eye <= 0)
			comp->ads[2] = 0;
		else
			specular_set(mat, light, comp, reflect_dot_eye);
		free(reflectv);
		free(temp);
	}
}

double	lighting(t_material *mat, t_plight *light,
				 double *pos, t_compute *comp)
{
	double	*temp;
	double	ret;

	temp = tuple_sub(light->position, pos);
	comp->lightv = vector_normalize(temp);
	if (comp->shadowed == 1)
	{
		comp->ads[1] = 0;
		comp->ads[2] = 0;
	}
	else
		diffuse_set(mat, light, comp);
	ret = comp->ads[1] + comp->ads[2];
	free(comp->obj_col);
	free(comp->lightv);
	free(temp);
	return (ret);
}
