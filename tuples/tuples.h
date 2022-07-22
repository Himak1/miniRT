/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tuples.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:50:18 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:50:31 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H
# define EPSILON 0.00001

double	*point(double x, double y, double z);
double	*vector(double x, double y, double z);

double	*tuple_add(double *tuple1, double *tuple2);
double	*tuple_sub(double *tuple1, double *tuple2);
double	*tuple_mult_alloc(double *tuple1, double scalar);
void	tuple_mult(double *tuple, double scalar);
void	tuple_div(double *tuple, double scalar);

double	dot_product(double *vector1, double *vector2);
double	*cross_product(double *vecto1, double *vector2);

double	*tuple_negate(double *tuple);

double	vector_magnitude(double *vector);
double	*vector_normalize(double *vector);
#endif
