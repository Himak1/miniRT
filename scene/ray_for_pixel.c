/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_for_pixel.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:47:18 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 20:56:08 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_error_exit.h"
#include "../matrix/rt_matrix.h"
#include "../tuples/tuples.h"
#include "../ptr_management/assign_free.h"
#include "scene.h"
#include <stdlib.h>

static double	*multiply_mtx_free_p(double **matrix, double *p)
{
	double	*return_value;

	return_value = mtx_x_tuple(matrix, p);
	free(p);
	return (return_value);
}

static t_ray	*return_ray(t_camera *cam, double *xy_world)
{
	double	*pixel;
	double	*origin;
	double	*direction;
	double	**temp;

	temp = cam->trans;
	pixel = multiply_mtx_free_p(temp, point(xy_world[0], xy_world[1], -1));
	origin = multiply_mtx_free_p(temp, point(0, 0, 0));
	direction = ft_callswp_t1(tuple_sub(pixel, origin), vector_normalize);
	free(pixel);
	return (ray(origin, direction));
}

t_ray	*ray_for_pixel(t_camera *cam, double px, double py)
{
	double	xy_offset[2];
	double	xy_world[2];
	t_ray	*ry;

	xy_offset[0] = (px + 0.5) * cam->pixel_size;
	xy_offset[1] = (py + 0.5) * cam->pixel_size;
	xy_world[0] = cam->half_width - xy_offset[0];
	xy_world[1] = cam->half_height - xy_offset[1];
	ry = return_ray(cam, xy_world);
	return (ry);
}
