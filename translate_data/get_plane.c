/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_plane.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:29:04 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/26 13:22:44 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include "../matrix/rt_matrix.h"
#include "../color/color.h"
#include "../ptr_management/assign_free.h"
#include <stdlib.h>

static void	get_size(t_shape *shp)
{
	double	**temp;

	temp = mtx_scaling(500, 500, 500);
	shp->transform = ft_callswp_m2(shp->transform, temp, mtx_multiply);
}

static void	get_pos(double *xyz, t_shape *shp)
{
	double	**temp;

	temp = mtx_translation(xyz[0], xyz[1], xyz[2]);
	shp->transform = ft_callswp_m2(shp->transform, temp, mtx_multiply);
}

static void	get_material(t_pl *pl, t_shape *shp, double amb)
{
	shp->material = material(amb);
	shp->material->color = convert_color(pl->rgb[0], pl->rgb[1], pl->rgb[2]);
}

void	get_plane(t_list *planes, t_world *w, int *i)
{
	t_list	*iter;
	t_pl	*pl_param;

	iter = planes;
	while (iter)
	{
		pl_param = (t_pl *)iter->content;
		w->shp[*i] = malloc(1 * sizeof(t_shape));
		w->shp[*i]->transform = mtx_identity();
		get_size(w->shp[*i]);
		get_pos(pl_param->pnt_xyz, w->shp[*i]);
		get_rotation(pl_param->vec_xyz, w->shp[*i]);
		get_material(pl_param, w->shp[*i], w->amb);
		w->shp[*i]->type = 'p';
		w->shp[*i]->id = *i;
		iter = iter->next;
		(*i)++;
	}
}
