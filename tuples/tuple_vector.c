/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tuple_vector.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:52:04 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:52:05 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../rt_error_exit.h"
#include <stdlib.h>
#include <math.h>

double	vector_magnitude(double *vector)
{
	double	temp[4];
	int		i;

	i = 0;
	ft_memcpy(temp, vector, 4 * sizeof(double));
	while (i < 4)
	{
		temp[i] *= temp[i];
		i++;
	}
	return (sqrt(temp[0] + temp[1] + temp[2] + temp[3]));
}

double	*vector_normalize(double *vector)
{
	double	*normalized;
	double	magnitude;
	int		i;

	i = 0;
	normalized = malloc(4 * sizeof(double));
	if (normalized == NULL)
		error_exit(MALLOC_F);
	magnitude = vector_magnitude(vector);
	while (i < 4)
	{
		if (!(vector[i] == 0 && magnitude == 0))
			normalized[i] = vector[i] / magnitude;
		else
			normalized[i] = 0.0;
		i++;
	}
	return (normalized);
}
