/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:49:59 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 13:07:03 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "../rays/rays.h"

typedef struct s_world {
	t_shape		**shp;
	int			num_shp;
	t_plight	*light;
	double		amb;
	double		*amb_rgb;
}				t_world;

typedef struct s_camera {
	double		hsize;
	double		vsize;
	double		fov;
	double		**trans;
	double		pixel_size;
	double		half_height;
	double		half_width;
}				t_camera;

t_camera	*camera(int hsize, int vsize, double fov);
double		radian(double degrees);
double		**view_transform(double *pos, double *direction);
double		*color_at(t_world *w, t_ray *r);
t_intersect	**intersect_world(t_world *w, t_ray *r);
double		*shade_hit(t_world *w, t_compute *comps);
int			is_shadowed(t_world *world, double *check_point);
void		prep_compute(t_intersect *i, t_ray *r, t_compute *compute);
t_ray		*ray_for_pixel(t_camera *cam, double px, double py);

#endif
