/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_array_free.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:58:09 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 19:58:12 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <stdlib.h>

void	intersect_free(t_intersect **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
