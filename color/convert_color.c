/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:52:36 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:25:55 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

double	*convert_color(int r, int g, int b)
{
	double	temp[3];
	double	*c;

	temp[0] = (double)r;
	temp[1] = (double)g;
	temp[2] = (double)b;
	c = color(1, 1, 1);
	c[0] = (c[0] / 255) * temp[0];
	c[1] = (c[1] / 255) * temp[1];
	c[2] = (c[2] / 255) * temp[2];
	return (c);
}
