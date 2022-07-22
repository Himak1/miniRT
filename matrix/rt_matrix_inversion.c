/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_inversion.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:49:07 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:49:30 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "rt_matrix.h"
#include "../rt_error_exit.h"
#include "../ptr_management/assign_free.h"

double	minor(double **matrix, int row, int col, int size)
{
	double	**sub;
	double	minor;

	sub = matrix;
	while (size != 2)
	{
		if (sub != matrix)
			mtx_free(sub, size);
		sub = sub_matrix(sub, row, col, size);
		size--;
	}
	minor = determinant_2(sub);
	mtx_free(sub, size);
	return (minor);
}

double	cofactor(double **matrix, int row, int col, int size)
{
	double	cofact;

	cofact = minor(matrix, row, col, size);
	if ((row + col) % 2 != 0)
		return (cofact * -1);
	else
		return (cofact);
}

static double	cofactor_4(double **matrix, int row, int col)
{
	double	**sub;
	double	cofact;

	sub = sub_matrix(matrix, row, col, 4);
	cofact = determinant_3(sub);
	mtx_free(sub, 3);
	if ((row + col) % 2 != 0)
		cofact *= -1;
	return (cofact);
}

static void	cofactor_loop(double ***inver, double determinant)
{
	int	j;
	int	i;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			(*inver)[j][i] /= determinant;
			i++;
		}
		j++;
	}
}

double	**mtx_inversion(double **matrix)
{
	int		i;
	int		j;
	double	determinant;
	double	**inver;

	j = 0;
	determinant = determinant_4(matrix);
	inver = mtx_malloc(4);
	if (inver == NULL)
		error_exit(MALLOC_F);
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			inver[j][i] = cofactor_4(matrix, j, i);
			i++;
		}
		j++;
	}
	inver = ft_callswp_m1(inver, mtx_transpose);
	cofactor_loop(&inver, determinant);
	return (inver);
}

/*
	- matrice_multiply() seems to work
	- mtx_transpose() is not the cause of the bug
	- mtx_inversion() gives wrong values by positives and negatives in some cases.
	Conclusion: forgot to implement cofactor in the cofact4() function

	- need to implement a function which swaps void pointers
*/
