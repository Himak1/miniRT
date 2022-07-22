/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_world.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:20:02 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 20:20:03 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	convert_trgb(double *colors)
{
	int	rgb[3];

	rgb[0] = colors[0] * 128;
	rgb[1] = colors[1] * 128;
	rgb[2] = colors[2] * 128;
	if (rgb[0] > 255)
	{
		rgb[0] = 255;
	}
	if (rgb[1] > 255)
	{
		rgb[1] = 255;
	}
	if (rgb[2] > 255)
	{
		rgb[2] = 255;
	}
	return (create_trgb(0, rgb[0], rgb[1], rgb[2]));
}

static void	raytracer(t_data *mlx, t_render *render)
{
	double	xy[2];
	double	*colors;
	int		trgb;
	t_ray	*r;

	xy[1] = 0;
	while (xy[1] < render->cam->vsize - 1)
	{
		xy[0] = 0;
		while (xy[0] < render->cam->hsize - 1)
		{
			r = ray_for_pixel(render->cam, xy[0], xy[1]);
			colors = color_at(render->w, r);
			trgb = convert_trgb(colors);
			pixel_put(mlx, xy[0], xy[1], trgb);
			free(colors);
			ray_free(r);
			xy[0]++;
		}
		xy[1]++;
	}
}

void	render_world(t_data *mlx, t_render *render)
{
	mlx_ini(mlx, render->cam);
	raytracer(mlx, render);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
