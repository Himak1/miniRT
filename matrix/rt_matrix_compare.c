/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_compare.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 12:33:01 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 12:33:02 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	mtx_comp(double **m_1, double **m_2, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (m_1[j][i] != m_2[j][i])
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}
