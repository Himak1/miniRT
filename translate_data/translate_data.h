/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_data.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:40:38 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:41:07 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATE_DATA_H
# define TRANSLATE_DATA_H
# include "../render/render.h"
# include "../parsing/parsing.h"

void	translate_data(t_stct *structs, t_render *render);
void	get_world(t_stct *structs, t_render *render);
void	get_camera(t_scene *scn, t_camera **cam);
void	get_light(t_lt *lt, t_plight *light);
void	get_sphere(t_list *s, t_world *w, int *i);
void	get_plane(t_list *planes, t_world *w, int *i);
void	get_cylinder(t_list *planes, t_world *w, int *i);
void	get_rotation(double *vec_xyz, t_shape *shp);
void	free_data(t_render *render);

#endif