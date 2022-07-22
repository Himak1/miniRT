/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assign_free.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:37:00 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:37:05 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSIGN_FREE_H
# define ASSIGN_FREE_H

double	*ft_callswp_t1(double *arg_tuple, double *(*func)(double*));
double	*ft_callswp_t2(double *arg_tuple1, double *arg_tuple2,
			double *(*func)(double*, double*));

double	*ft_callswp_mt(double **arg_matrix, double *arg_tuple,
			double *(*func)(double**, double *));

double	**ft_callswp_m1(double **arg_matrix, double **(*func)(double**));

double	**ft_callswp_m2(double **arg_matrix1, double **arg_matrix2,
			double **(*func)(double**, double**));
#endif
