/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tuple_negate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:50:05 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:50:06 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../rt_error_exit.h"

double	*tuple_negate(double *tuple)
{
	double	*ret;
	int		i;

	i = 0;
	ret = ft_calloc(4, sizeof(double));
	if (ret == NULL)
		error_exit(MALLOC_F);
	while (i < 4)
	{
		ret[i] = tuple[i] * -1;
		i++;
	}
	return (ret);
}
