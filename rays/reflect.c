/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reflect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:49:01 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:49:05 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tuples/tuples.h"
#include "../libft/libft.h"

double	*reflect(double *in, double *normal)
{
	double	*ret;
	double	temp[4];

	ft_memcpy(temp, normal, 4 * sizeof(double));
	tuple_mult(temp, 2);
	tuple_mult(temp, dot_product(in, normal));
	ret = tuple_sub(in, temp);
	return (ret);
}
