/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_free.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:50:12 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:50:12 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <stdlib.h>

void	ray_free(t_ray *r)
{
	free(r->direction);
	free(r->origin);
	free(r);
}
