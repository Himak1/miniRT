/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   amb_set.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:27:14 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 18:20:06 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	amb_set(char *line[], t_stct *structs)
{
	if (structs->amb_ini == 1)
		error_exit(RACL_MULT);
	if (ptr_arraylen(line) != 3)
		error_exit(MISSING_PARAM);
	structs->scene->amb_ratio = extract_double(line[1]);
	if (structs->scene->amb_ratio < 0 || structs->scene->amb_ratio > 1)
		error_exit(LIGHT_INV);
	tri_int_set(line[2], structs->scene->amb_rgb);
	rgb_check(structs->scene->amb_rgb);
	structs->amb_ini = 1;
}
