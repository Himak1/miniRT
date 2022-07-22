/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cylinder.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:25:51 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/26 13:24:32 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include "../matrix/rt_matrix.h"
#include "../color/color.h"
#include "../ptr_management/assign_free.h"
#include <stdlib.h>

static void	get_size(double dia, double height, t_shape *shp)
{
	double	**temp;
	t_cylin	*ptr;

	temp = mtx_scaling(dia, height, dia);
	shp->transform = ft_callswp_m2(temp, shp->transform, mtx_multiply);
	shp->shp_data = malloc(sizeof(t_cylin));
	if (!shp->shp_data)
		error_exit(MALLOC_F);
	ptr = shp->shp_data;
	ptr->max = height * 0.5;
	ptr->min = height * -0.5;
}

static void	get_position(double *pos, t_shape *shp)
{
	double	**temp;

	temp = mtx_translation(pos[0], pos[1], pos[2]);
	shp->transform = ft_callswp_m2(temp, shp->transform, mtx_multiply);
}

static void	get_material(int *rgb, t_shape *shp, double amb)
{
	shp->material = material(amb);
	shp->material->color = convert_color(rgb[0], rgb[1], rgb[2]);
}

void	get_cylinder(t_list *cylinder, t_world *w, int *i)
{
	t_list	*iter;
	t_cy	*cy_param;

	iter = cylinder;
	while (iter)
	{
		cy_param = (t_cy *)iter->content;
		w->shp[*i] = malloc(1 * sizeof(t_shape));
		if (!w->shp[*i])
			error_exit(MALLOC_F);
		w->shp[*i]->transform = mtx_identity();
		get_position(cy_param->pnt_xyz, w->shp[*i]);
		get_rotation(cy_param->vec_xyz, w->shp[*i]);
		get_size(cy_param->dia, cy_param->hei, w->shp[*i]);
		get_material(cy_param->rgb, w->shp[*i], w->amb);
		w->shp[*i]->type = 'c';
		w->shp[*i]->id = *i;
		iter = iter->next;
		(*i)++;
	}
}
