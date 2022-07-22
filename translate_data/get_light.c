/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_light.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:29:00 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:29:00 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_data.h"
#include "../tuples/tuples.h"
#include "../color/color.h"

void	get_light(t_lt *lt, t_plight *light)
{
	light->position = point(lt->xyz[0], lt->xyz[1], lt->xyz[2]);
	light->intensity = color(lt->ratio, lt->ratio, lt->ratio);
}
