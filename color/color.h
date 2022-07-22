/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:52:39 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/26 17:26:40 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

double	*color(double r, double g, double b);
double	*convert_color(int r, int g, int b);
double	*color_mult(double *c1, double *c2);
#endif
