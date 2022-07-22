/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light_set.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:35:07 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 18:21:56 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	light_set(char *line[], t_stct *structs)
{
	t_lt	*content;

	if (structs->light_ini == 1)
		error_exit(RACL_MULT);
	content = structs->light;
	if (ptr_arraylen(line) != 4)
		error_exit(MISSING_PARAM);
	tri_int_set(line[3], content->rgb);
	rgb_check(content->rgb);
	tri_dbl_set(line[1], content->xyz);
	content->ratio = extract_double(line[2]);
	if (content->ratio < 0 || content->ratio > 1)
		error_exit(LIGHT_INV);
	structs->light_ini = 1;
}
