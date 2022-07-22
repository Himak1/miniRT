/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_ptrlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:27:36 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:27:58 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ptr_arraylen(char **ptr_array)
{
	int	i;

	i = 0;
	while (ptr_array[i] != NULL)
		i++;
	return (i);
}
