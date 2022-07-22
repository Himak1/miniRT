/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_data.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:40:08 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 18:27:55 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include <stdlib.h>

static void	parameter_check(t_stct *structs)
{
	if (structs->amb_ini == 0)
		error_exit(MISSING_PARAM);
	if (structs->cam_ini == 0)
		error_exit(MISSING_PARAM);
	if (structs->light_ini == 0)
		error_exit(MISSING_PARAM);
}

void	translate_data(t_stct *structs, t_render *render)
{
	int	i;

	i = 0;
	parameter_check(structs);
	render->w = malloc(1 * sizeof(t_world));
	render->w->light = malloc(1 * sizeof(t_plight));
	if (!render->w || !render->w->light)
		error_exit(MALLOC_F);
	get_world(structs, render);
	get_camera(structs->scene, &render->cam);
	get_light(structs->light, render->w->light);
	get_sphere(structs->sphere, render->w, &i);
	get_plane(structs->plane, render->w, &i);
	get_cylinder(structs->cylinder, render->w, &i);
}
