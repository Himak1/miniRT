/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_x_tuple.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:50:56 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:50:57 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../rt_error_exit.h"
#include "rt_matrix.h"

double	*mtx_x_tuple(double **trans_matrix, double *tuple)
{
	double	*ret;
	int		i;
	int		j;

	j = 0;
	ret = ft_calloc(4, sizeof(double));
	if (ret == NULL)
		error_exit(MALLOC_F);
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			ret[j] += trans_matrix[i][j] * tuple[i];
			i++;
		}
		j++;
	}
	return (ret);
}
