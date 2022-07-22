/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:27:10 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 22:01:19 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_error_exit.h"
#include "scene.h"
#include "../matrix/rt_matrix.h"
#include <stdlib.h>
#include <math.h>

static void	calc_pixel_size(t_camera *cam)
{
	double	half_view;
	double	aspect;
	double	fov_radians;

	fov_radians = radian(cam->fov);
	half_view = tan(fov_radians / 2);
	aspect = cam->hsize / cam->vsize;
	if (aspect >= 1)
	{
		cam->half_width = half_view;
		cam->half_height = half_view / aspect;
	}
	else
	{
		cam->half_width = half_view * aspect;
		cam->half_height = half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->hsize;
}

t_camera	*camera(int hsize, int vsize, double fov)
{
	t_camera	*cam;

	cam = malloc(1 * sizeof(t_camera));
	if (!cam)
		error_exit(MALLOC_F);
	cam->hsize = hsize;
	cam->vsize = vsize;
	cam->fov = fov;
	calc_pixel_size(cam);
	return (cam);
}
