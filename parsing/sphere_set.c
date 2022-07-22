/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_set.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:33:17 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/23 00:45:23 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	sphere_set(char *line[], t_stct *structs)
{
	t_sp	*content;
	t_list	*node;

	if (ptr_arraylen(line) != 4)
		error_exit(MISSING_PARAM);
	content = ft_calloc(1, sizeof(struct s_sp));
	node = ft_lstnew(content);
	if (node_check(node, content) == -1)
		error_exit(MALLOC_F);
	tri_dbl_set(line[1], content->xyz);
	content->dia = extract_double(line[2]);
	if (content->dia < 0.00001)
		error_exit(SIZE_INV);
	tri_int_set(line[3], content->rgb);
	rgb_check(content->rgb);
	if (structs->sphere == NULL)
		structs->sphere = (void *)node;
	else
		ft_lstadd_back(&structs->sphere, (void *)node);
}
