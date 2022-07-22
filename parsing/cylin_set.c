/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylin_set.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:28:22 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 16:28:13 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	cylin_set(char *line[], t_stct *structs)
{
	t_cy	*content;
	t_list	*node;

	if (ptr_arraylen(line) != 6)
		error_exit(MISSING_PARAM);
	content = ft_calloc(1, sizeof(struct s_cy));
	node = ft_lstnew(content);
	if (node_check(node, content) == -1)
		error_exit(MALLOC_F);
	tri_dbl_set(line[1], content->pnt_xyz);
	tri_dbl_set(line[2], content->vec_xyz);
	vector_valid(content->vec_xyz);
	content->dia = extract_double(line[3]);
	content->hei = extract_double(line[4]);
	if (content->dia <= 0.00001 || content->hei <= 0.00001)
		error_exit(SIZE_INV);
	tri_int_set(line[5], content->rgb);
	rgb_check(content->rgb);
	if (structs->cylinder == NULL)
		structs->cylinder = (void *)node;
	else
		ft_lstadd_back(&structs->cylinder, (void *)node);
}
