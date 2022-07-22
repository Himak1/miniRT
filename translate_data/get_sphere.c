/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_sphere.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:38:30 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/26 13:23:34 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include "../color/color.h"
#include "../tuples/tuples.h"
#include "../matrix/rt_matrix.h"
#include "../ptr_management/assign_free.h"
#include <stdlib.h>

static void	get_size(t_sp *s_p, t_shape *s)
{
	double	**temp;

	temp = mtx_scaling(s_p->dia, s_p->dia, s_p->dia);
	s->transform = ft_callswp_m2(temp, s->transform, mtx_multiply);
}

static void	get_pos(t_sp *s_p, t_shape *s)
{
	double	**temp;

	temp = mtx_translation(s_p->xyz[0], s_p->xyz[1], s_p->xyz[2]);
	s->transform = ft_callswp_m2(temp, s->transform, mtx_multiply);
}

static void	get_material(t_sp *s_p, t_shape *s, double amb)
{
	t_material	*m;

	s->material = material(amb);
	m = s->material;
	m->color = convert_color(s_p->rgb[0], s_p->rgb[1], s_p->rgb[2]);
}

void	get_sphere(t_list *sp, t_world *w, int *i)
{
	t_list	*iter;
	t_sp	*s_param;

	iter = sp;
	while (iter)
	{
		s_param = (t_sp *)iter->content;
		w->shp[*i] = malloc(1 * sizeof(t_shape));
		if (!w->shp[*i])
			error_exit(MALLOC_F);
		w->shp[*i]->transform = mtx_identity();
		get_pos(s_param, w->shp[*i]);
		get_size(s_param, w->shp[*i]);
		get_material(s_param, w->shp[*i], w->amb);
		w->shp[*i]->type = 's';
		w->shp[*i]->id = *i;
		iter = iter->next;
		(*i)++;
	}
}
