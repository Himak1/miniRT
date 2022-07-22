/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_error_exit.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 22:09:38 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 16:09:17 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_EXIT_H
# define RT_ERROR_EXIT_H
# define CLEAN 0
# define MALLOC_F -1
# define NO_FILE -2
# define BAD_EXTENSION -3
# define OPEN_F -4
# define RES_HIGH -5
# define VEC_INV -6
# define RGB_INV -7
# define FOV_INV -8
# define RACL_MULT -9
# define IDEN_INV -10
# define MISSING_PARAM -11
# define NOT_INT -12
# define NOT_DBL -13
# define LIGHT_INV -14
# define SIZE_INV -15
# define TOO_MANY_COMMAS -16

void	error_exit(int error_code);
#endif
