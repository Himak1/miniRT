/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   res_set.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:34:32 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 18:22:50 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	res_set(char *line[], t_stct *structs)
{
	if (structs->res_ini == 1)
		error_exit(RACL_MULT);
	if (ptr_arraylen(line) != 3)
		error_exit(MISSING_PARAM);
	if (line[1][0] == '0' || line[2][0] == '0')
		error_exit(RES_HIGH);
	structs->scene->x_render = extract_int(line[1]);
	structs->scene->y_render = extract_int(line[2]);
	if (structs->scene->x_render > 5120 || structs->scene->y_render > 2880)
		error_exit(RES_HIGH);
	if (structs->scene->x_render < 1 || structs->scene->y_render < 1)
		error_exit(RES_HIGH);
	structs->res_ini = 1;
}
