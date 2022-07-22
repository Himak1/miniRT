/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_mult.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/26 17:18:51 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/26 17:26:25 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_error_exit.h"
#include <stdlib.h>

double	*color_mult(double *c1, double *c2)
{
	double	*color;

	color = malloc(3 * sizeof(double));
	if (color == NULL)
		error_exit(MALLOC_F);
	color[0] = c1[0] * c2[0];
	color[1] = c1[1] * c2[1];
	color[2] = c1[2] * c2[2];
	return (color);
}
