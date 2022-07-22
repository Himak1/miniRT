/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:49:12 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 13:32:53 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H
# include "../libft/libft.h"

typedef struct s_ray {
	double		*origin;
	double		*direction;
}				t_ray;

typedef struct s_material {
	double		*color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;

typedef struct s_shape {
	t_material	*material;
	double		**transform;
	void		*shp_data;
	char		type;
	int			id;
}				t_shape;

typedef struct s_cylin {
	double		min;
	double		max;
}				t_cylin;

typedef struct s_intersect {
	double		t;
	t_shape		*obj;
}				t_intersect;

typedef struct s_plight {
	double		*intensity;
	double		*position;
}				t_plight;

typedef struct s_compute {
	double		t;
	t_shape		*shp;
	double		*p;
	double		*eyev;
	double		*normalv;
	double		*lightv;
	double		*over_p;
	double		*obj_col;
	double		ads[3];
	int			inside;
	int			shadowed;
}				t_compute;

int				equal(double a, double b);
double			sqr(double a);

t_shape			*sphere(void);
t_ray			*ray(double *origin_og, double *direction_og);
void			ray_free(t_ray *r);

double			*normal_at(t_shape *shp, double *world_p);
double			*sphere_normal_at(t_shape *s, double *world_p);
double			*cylinder_normal_at(t_shape *shp, double *world_p);

void			set_transform(t_shape *s, double **translation);
double			*reflect(double *in, double *normal);

t_material		*material(double ambient);
t_plight		*point_light(double *pos, double *intens);
double			lighting(t_material *mat, t_plight *light,
					double *pos, t_compute *comp);

int				intersect(t_intersect **array, int j, t_shape *shp, t_ray *ry);
int				sp_intersect(t_intersect **array, int j, t_shape *s, t_ray *r);
int				plane_intersect(t_intersect **array,
					int j, t_shape *shp, t_ray *ry);
int				cylinder_intersect(t_intersect **array,
					int j, t_shape *shp, t_ray *ry);
void			intersect_free(t_intersect **array);

t_intersect		*intersection(double t_value, t_shape *obj_ptr);
t_intersect		*hit(t_intersect **inter_arr);

double			*ray_position(t_ray *ray, double time);
t_ray			*ray_transform(t_ray *r, double **trans_matrix);
#endif
