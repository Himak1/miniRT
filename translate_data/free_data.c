/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:14:26 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 13:11:19 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include "../matrix/rt_matrix.h"
#include <stdlib.h>

static void	free_world(t_render *render)
{
	int	i;

	i = 0;
	free(render->w->light->intensity);
	free(render->w->light->position);
	free(render->w->light);
	while (i < render->w->num_shp)
	{
		mtx_free(render->w->shp[i]->transform, 4);
		if (render->w->shp[i]->type == 'c')
			free(render->w->shp[i]->shp_data);
		free(render->w->shp[i]->material->color);
		free(render->w->shp[i]->material);
		free(render->w->shp[i]);
		i++;
	}
	free(render->w->shp);
	free(render->w->amb_rgb);
	free(render->w);
}

static void	free_cam(t_render *render)
{
	mtx_free(render->cam->trans, 4);
	free(render->cam);
}

void	free_data(t_render *render)
{
	free_world(render);
	free_cam(render);
}
