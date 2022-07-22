/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_ini.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:52:34 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:54:27 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../rt_error_exit.h"

double	*color(double r, double g, double b)
{
	double	*rgb;

	rgb = malloc(3 * sizeof(double));
	if (rgb == NULL)
		error_exit(MALLOC_F);
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (rgb);
}
