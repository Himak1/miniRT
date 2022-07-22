/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_multiply.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:49:38 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:49:39 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rt_matrix.h"

static	double	multiply(double **m_1, double **m_2, int j, int i)
{
	double	ret;
	int		x;

	x = 0;
	ret = 0;
	while (x < 4)
	{
		ret += m_1[j][x] * m_2[x][i];
		x++;
	}
	return (ret);
}

double	**mtx_multiply(double **m_1, double **m_2)
{
	double	**ret;
	int		i;
	int		j;

	ret = 0;
	j = 0;
	ret = mtx_malloc(4);
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			ret[j][i] = multiply(m_1, m_2, j, i);
			i++;
		}
		j++;
	}
	return (ret);
}
