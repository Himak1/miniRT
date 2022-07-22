/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_ini.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:19:55 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 20:19:56 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../mlx/mlx.h"

void	mlx_ini(t_data *mlx, t_camera *cam)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, cam->hsize, cam->vsize, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, cam->hsize, cam->vsize);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
}
