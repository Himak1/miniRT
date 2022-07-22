/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_scaling.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:50:08 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:50:10 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rt_matrix.h"
#include "../libft/libft.h"
#include "../rt_error_exit.h"

/*
** mtx_scaling() takes scaling[] inserts it to create a scaling matrix
*/

double	**mtx_scaling(double x, double y, double z)
{
	double	**scale_matrix;

	scale_matrix = mtx_malloc(4);
	scale_matrix[0][0] = x;
	scale_matrix[1][1] = y;
	scale_matrix[2][2] = z;
	scale_matrix[3][3] = 1.0;
	return (scale_matrix);
}
