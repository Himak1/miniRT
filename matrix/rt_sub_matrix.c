/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_sub_matrix.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:51:06 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:51:07 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rt_matrix.h"

static void	ini_array(int (*i)[], int (*j)[])
{
	(*i)[0] = 0;
	(*i)[1] = 0;
	(*j)[0] = 0;
	(*j)[1] = 0;
}

static void	iterate(int (*i)[], int (*j)[], int size)
{
	(*i)[1] += 1;
	if ((*i)[1] == size - 1)
	{
		(*i)[1] = 0;
		(*j)[1] += 1;
	}
}

double	**sub_matrix(double **matrix, int row, int col, int size)
{
	double	**sub;
	int		i[2];
	int		j[2];

	sub = mtx_malloc(size - 1);
	ini_array(&i, &j);
	while (j[1] < size - 1 && j[0] <= size)
	{
		i[0] = 0;
		while (i[1] < size - 1 && i[0] < size)
		{
			if (j[0] != row && i[0] != col)
			{
				sub[j[1]][i[1]] = matrix[j[0]][i[0]];
				iterate(&i, &j, size);
			}
			i[0] += 1;
		}
		j[0] += 1;
	}
	return (sub);
}
