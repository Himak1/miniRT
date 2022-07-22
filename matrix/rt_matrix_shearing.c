/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_shearing.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:50:13 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:50:14 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../rt_error_exit.h"
#include "rt_matrix.h"

double	**shear_param(void)
{
	double	**ret;
	int		i;

	i = 0;
	ret = ft_calloc(3, sizeof(double *));
	if (ret == NULL)
		error_exit(MALLOC_F);
	while (i < 3)
	{
		ret[i] = ft_calloc(2, sizeof(double));
		if (ret[i] == NULL)
			error_exit(MALLOC_F);
		i++;
	}
	return (ret);
}

double	**mtx_shearing(double *x, double *y, double *z)
{
	double	**matrix;
	int		i;

	i = 0;
	matrix = mtx_malloc(4);
	while (i < 4)
	{
		matrix[i][i] = 1.0;
		i++;
	}
	matrix[1][0] = x[0];
	matrix[2][0] = x[1];
	matrix[0][1] = y[0];
	matrix[2][1] = y[1];
	matrix[0][2] = z[0];
	matrix[1][2] = z[1];
	return (matrix);
}
