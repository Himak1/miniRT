/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:57:19 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/26 13:22:09 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "../rt_error_exit.h"
#include <stdlib.h>

t_material	*material(double ambient)
{
	t_material	*mat;

	mat = malloc(1 * sizeof(t_material));
	if (mat == NULL)
		error_exit(MALLOC_F);
	mat->ambient = ambient;
	mat->diffuse = 0.9;
	mat->specular = 0.9;
	mat->shininess = 200;
	return (mat);
}
