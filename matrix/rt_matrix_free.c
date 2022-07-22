/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 12:33:19 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 12:33:20 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	mtx_free(double **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
