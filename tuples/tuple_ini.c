/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tuple_ini.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:50:42 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:51:04 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../rt_error_exit.h"

static double	*tuple_ini(double x, double y, double z)
{
	double	*ret;

	ret = ft_calloc(4, sizeof(double));
	if (ret == NULL)
		error_exit(MALLOC_F);
	ret[0] = x;
	ret[1] = y;
	ret[2] = z;
	return (ret);
}

double	*point(double x, double y, double z)
{
	double	*ret;

	ret = tuple_ini(x, y, z);
	ret[3] = 1;
	return (ret);
}

double	*vector(double x, double y, double z)
{
	double	*ret;

	ret = tuple_ini(x, y, z);
	ret[3] = 0;
	return (ret);
}
