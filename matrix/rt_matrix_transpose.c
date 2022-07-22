/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_transpose.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:50:52 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:50:53 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rt_matrix.h"

double	**mtx_transpose(double **matrix)
{
	double	**ret;
	int		row;
	int		col;

	row = 0;
	ret = mtx_malloc(4);
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ret[row][col] = matrix[col][row];
			col++;
		}
		row++;
	}
	return (ret);
}
