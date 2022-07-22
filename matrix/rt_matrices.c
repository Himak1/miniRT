/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrices.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 12:32:27 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 12:32:57 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "rt_matrix.h"
#include "../rt_error_exit.h"

/*
** matrice_malloc takes int SIZE
** which determines the dimensions of the matrix(SIZE x SIZE)
*/

double	**mtx_malloc(int size)
{
	double	**ptr;
	int		i;

	i = 0;
	ptr = ft_calloc(size, sizeof(double *));
	if (ptr == NULL)
		error_exit(MALLOC_F);
	while (i < size)
	{
		ptr[i] = ft_calloc(size, sizeof(double));
		if (ptr[i] == NULL)
			error_exit(MALLOC_F);
		i++;
	}
	return (ptr);
}

double	**mtx_4(double array[])
{
	double	**ptr;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	ptr = mtx_malloc(4);
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			ptr[j][i] = array[k];
			k++;
			i++;
		}
		j++;
	}
	return (ptr);
}

double	**mtx_3(double *arr1, double *arr2, double *arr3)
{
	double	**ptr;

	ptr = mtx_malloc(3);
	ptr[0] = arr1;
	ptr[1] = arr2;
	ptr[2] = arr3;
	return (ptr);
}

double	**mtx_2(double *arr1, double *arr2)
{
	double	**ptr;

	ptr = mtx_malloc(2);
	ptr[0] = arr1;
	ptr[1] = arr2;
	return (ptr);
}
