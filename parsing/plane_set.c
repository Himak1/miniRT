/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_set.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:34:21 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/25 15:18:13 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	plane_set(char *line[], t_stct *structs)
{
	t_pl	*content;
	t_list	*node;

	if (ptr_arraylen(line) != 4)
		error_exit(MISSING_PARAM);
	content = ft_calloc(1, sizeof(struct s_pl));
	node = ft_lstnew(content);
	if (node_check(node, content) == -1)
		error_exit(MALLOC_F);
	tri_dbl_set(line[1], content->pnt_xyz);
	tri_dbl_set(line[2], content->vec_xyz);
	vector_valid(content->vec_xyz);
	tri_int_set(line[3], content->rgb);
	rgb_check(content->rgb);
	if (structs->plane == NULL)
		structs->plane = (void *)node;
	else
		ft_lstadd_back(&structs->plane, (void *)node);
}
