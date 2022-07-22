/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tuple_calc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:51:35 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:51:51 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../rt_error_exit.h"
#include "tuples.h"
#include <stdlib.h>

double	*tuple_add(double *tuple1, double *tuple2)
{
	double	*ret;
	int		i;

	i = 0;
	ret = ft_calloc(4, sizeof(double));
	if (ret == NULL)
		error_exit(MALLOC_F);
	while (i < 4)
	{
		ret[i] = tuple1[i] + tuple2[i];
		i++;
	}
	return (ret);
}

double	*tuple_sub(double *tuple1, double *tuple2)
{
	double	*ret;
	int		i;

	i = 0;
	ret = ft_calloc(4, sizeof(double));
	if (ret == NULL)
		error_exit(MALLOC_F);
	while (i < 4)
	{
		ret[i] = tuple1[i] - tuple2[i];
		i++;
	}
	return (ret);
}

double	*tuple_mult_alloc(double *tuple1, double scalar)
{
	double	*ret;

	ret = malloc(4 * sizeof(double));
	if (ret == NULL)
		error_exit(MALLOC_F);
	ft_memcpy(ret, tuple1, 4 * sizeof(double));
	tuple_mult(ret, scalar);
	return (ret);
}

void	tuple_mult(double *tuple, double scalar)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tuple[i] *= scalar;
		i++;
	}
}

void	tuple_div(double *tuple, double scalar)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tuple[i] /= scalar;
		i++;
	}
}
