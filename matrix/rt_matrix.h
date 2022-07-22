/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_matrix.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:51:03 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/25 15:03:19 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATRIX_H
# define RT_MATRIX_H

double	**mtx_multiply(double **m_1, double **m_2);

double	**mtx_malloc(int size);
double	**mtx_4(double array[]);
double	**mtx_3(double *arr1, double *arr2, double *arr3);
double	**mtx_2(double *arr1, double *arr2);

double	determinant_2(double **matrix);
double	determinant_3(double **matrix);
double	determinant_4(double **matrix);

double	**mtx_identity(void);
double	**mtx_translation(double x, double y, double z);
double	**mtx_scaling(double x, double y, double z);
double	**mtx_rotation(double *xyz);

double	**shear_param(void);
double	**mtx_shearing(double *x, double *y, double *z);

double	*mtx_x_tuple(double **trans_matrix, double *tuple);

int		mtx_comp(double **m_1, double **m_2, int size);

double	**mtx_transpose(double **matrix);

double	**mtx_inversion(double **matrix);

double	**sub_matrix(double **matrix, int row, int col, int size);

void	mtx_free(double **matrix, int size);

double	cofactor(double **matrix, int row, int col, int size);
double	minor(double **matrix, int row, int col, int size);
#endif
