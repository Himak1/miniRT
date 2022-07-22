/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_set_transform.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:38:27 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:38:28 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../matrix/rt_matrix.h"

void	set_transform(t_shape *s, double **translation)
{
	double	**ptr;

	ptr = s->transform;
	s->transform = translation;
	mtx_free(ptr, 4);
}
