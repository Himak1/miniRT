/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_camera.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:21:01 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 15:32:32 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include "../tuples/tuples.h"
#include <stdlib.h>

void	get_camera(t_scene *scn, t_camera **cam)
{
	double	*pos;
	double	*direct;

	pos = point(scn->cam_xyz[0], scn->cam_xyz[1], scn->cam_xyz[2]);
	if (scn->x_render == 0 && scn->y_render == 0)
	{
		scn->x_render = 1920;
		scn->y_render = 1080;
	}
	direct = vector(scn->vec_xyz[0], scn->vec_xyz[1], scn->vec_xyz[2]);
	*cam = camera(scn->x_render, scn->y_render, (double)scn->cam_fov);
	(*cam)->trans = view_transform(pos, direct);
	(*cam)->fov = (double)scn->cam_fov;
	free(pos);
	free(direct);
}
