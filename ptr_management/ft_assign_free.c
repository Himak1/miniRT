/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_assign_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:36:51 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:36:52 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../matrix/rt_matrix.h"

double	*ft_callswp_t1(double *arg_tuple, double *(*func)(double*))
{
	double	*ret;

	ret = func(arg_tuple);
	free(arg_tuple);
	return (ret);
}

double	*ft_callswp_t2(double *arg_tuple1, double *arg_tuple2,
						double *(*func)(double*, double*))
{
	double	*ret;

	ret = func(arg_tuple1, arg_tuple2);
	free(arg_tuple1);
	free(arg_tuple2);
	return (ret);
}

double	*ft_callswp_mt(double **arg_matrix, double *arg_tuple,
						double *(*func)(double**, double *))
{
	double	*ret;

	ret = func(arg_matrix, arg_tuple);
	free(arg_tuple);
	mtx_free(arg_matrix, 4);
	return (ret);
}

double	**ft_callswp_m1(double **arg_matrix, double **(*func)(double**))
{
	double	**ret;

	ret = func(arg_matrix);
	mtx_free(arg_matrix, 4);
	return (ret);
}

double	**ft_callswp_m2(double **arg_matrix1, double **arg_matrix2,
						double **(*func)(double**, double**))
{
	double	**ret;

	ret = func(arg_matrix1, arg_matrix2);
	mtx_free(arg_matrix1, 4);
	mtx_free(arg_matrix2, 4);
	return (ret);
}
