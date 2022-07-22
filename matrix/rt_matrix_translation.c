/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_translation.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:50:46 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:50:47 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rt_matrix.h"

double	**mtx_translation(double x, double y, double z)
{
	int		i;
	double	**trans_matrix;

	i = 0;
	trans_matrix = mtx_malloc(4);
	while (i < 4)
	{
		trans_matrix[i][i] = 1;
		i++;
	}
	trans_matrix[3][0] = x;
	trans_matrix[3][1] = y;
	trans_matrix[3][2] = z;
	return (trans_matrix);
}
