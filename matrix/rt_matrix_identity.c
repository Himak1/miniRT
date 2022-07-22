/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix_identity.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:48:53 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 17:48:58 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../rt_error_exit.h"
#include <stdlib.h>

double	**mtx_identity(void)
{
	double	**identity_matrix;
	int		i;

	i = 0;
	identity_matrix = malloc(4 * sizeof(double *));
	if (identity_matrix == NULL)
		error_exit(MALLOC_F);
	while (i < 4)
	{
		identity_matrix[i] = ft_calloc(4, sizeof(double));
		if (identity_matrix[i] == NULL)
			error_exit(MALLOC_F);
		identity_matrix[i][i] = 1.0;
		i++;
	}
	return (identity_matrix);
}
