/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:50:19 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:50:20 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <stdlib.h>
#include "../rt_error_exit.h"

t_plight	*point_light(double *pos, double *intens)
{
	t_plight	*ret;

	ret = malloc(1 * sizeof(t_plight));
	if (ret == NULL)
		error_exit(MALLOC_F);
	ret->intensity = intens;
	ret->position = pos;
	return (ret);
}
