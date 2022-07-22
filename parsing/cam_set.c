/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_set.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:27:26 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 18:22:07 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	cam_set(char *line[], t_stct *structs)
{
	if (structs->cam_ini == 1)
		error_exit(RACL_MULT);
	if (ptr_arraylen(line) != 4)
		error_exit(MISSING_PARAM);
	tri_dbl_set(line[1], structs->scene->cam_xyz);
	tri_dbl_set(line[2], structs->scene->vec_xyz);
	vector_valid(structs->scene->vec_xyz);
	structs->scene->cam_fov = extract_int(line[3]);
	if (structs->scene->cam_fov > 180 || structs->scene->cam_fov < 1)
		error_exit(FOV_INV);
	structs->cam_ini = 1;
}
