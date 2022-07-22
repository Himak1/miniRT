/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trgb.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 15:25:08 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:25:14 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
