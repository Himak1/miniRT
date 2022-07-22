/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_put.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 20:19:58 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 20:19:59 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../mlx/mlx.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
