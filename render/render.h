/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:20:11 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 20:20:12 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "../rays/rays.h"
# include "../scene/scene.h"
# include "../minirt.h"

typedef struct s_render {
	t_compute	*comp;
	t_camera	*cam;
	t_world		*w;
}				t_render;

void	mlx_ini(t_data *mlx, t_camera *cam);
void	pixel_put(t_data *data, int x, int y, int color);
void	render_world(t_data *mlx, t_render *render);

#endif
