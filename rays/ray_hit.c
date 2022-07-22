/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_hit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:49:44 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/24 12:30:18 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../libft/libft.h"
#include <math.h>

t_intersect	*hit(t_intersect **inter_arr)
{
	int			i;
	double		t_value;
	t_intersect	*hit_i;

	i = 0;
	t_value = INFINITY;
	hit_i = NULL;
	while (inter_arr[i])
	{
		if (inter_arr[i]->t > 0.00001 && inter_arr[i]->t < t_value - 0.00001)
		{
			t_value = inter_arr[i]->t;
			hit_i = inter_arr[i];
		}
		i++;
	}
	return (hit_i);
}
