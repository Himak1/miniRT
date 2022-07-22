/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   world.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 21:05:41 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 21:05:52 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_error_exit.h"
#include "scene.h"
#include <stdlib.h>

t_world	*world(void)
{
	t_world	*ret;

	ret = malloc(1 * sizeof(t_world));
	if (ret == NULL)
		error_exit(MALLOC_F);
	return (ret);
}
