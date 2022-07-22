/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_determinant.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 12:33:11 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 12:33:12 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rt_matrix.h"

double	determinant_2(double **matrix)
{
	double	prod1;
	double	prod2;

	prod1 = matrix[0][0] * matrix[1][1];
	prod2 = matrix[0][1] * matrix[1][0];
	return (prod1 - prod2);
}

double	determinant_3(double **matrix)
{
	double	determinant;
	double	cofact;
	int		i;

	i = 0;
	determinant = 0;
	while (i < 3)
	{
		cofact = cofactor(matrix, 0, i, 3);
		determinant += (matrix[0][i] * cofact);
		i++;
	}
	return (determinant);
}

double	determinant_4(double **matrix)
{
	int		i;
	double	determinant;
	double	cofact;
	double	**sub;

	i = 0;
	determinant = 0;
	while (i < 4)
	{
		sub = sub_matrix(matrix, 0, i, 4);
		cofact = determinant_3(sub);
		if (i % 2 != 0)
			cofact *= -1;
		determinant += (matrix[0][i] * cofact);
		mtx_free(sub, 3);
		i++;
	}
	return (determinant);
}
