/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_world.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:39:50 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 14:51:10 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include "../color/color.h"
#include <stdlib.h>

static void	get_amb(t_scene *scn, t_render *render)
{
	render->w->amb = scn->amb_ratio;
	render->w->amb_rgb = convert_color(scn->amb_rgb[0],
			scn->amb_rgb[1],
			scn->amb_rgb[2]);
}

void	get_world(t_stct *structs, t_render *render)
{
	t_scene	*scn;
	int		shapes_count[3];
	int		total_obj_count;

	scn = structs->scene;
	shapes_count[0] = ft_lstsize(structs->cylinder);
	shapes_count[1] = ft_lstsize(structs->plane);
	shapes_count[2] = ft_lstsize(structs->sphere);
	total_obj_count = shapes_count[0] + shapes_count[1] + shapes_count[2];
	render->w->shp = malloc(total_obj_count * sizeof(t_shape *));
	if (!render->w->shp)
		error_exit(MALLOC_F);
	render->w->num_shp = total_obj_count;
	get_amb(scn, render);
}
