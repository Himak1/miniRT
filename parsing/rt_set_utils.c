/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_set_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:35:49 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/25 15:17:54 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../rt_error_exit.h"
#include <stdlib.h>
#include <math.h>

int	node_check(void *ptr1, void *ptr2)
{
	if (ptr1 == NULL)
	{
		free(ptr2);
		return (-1);
	}
	if (ptr2 == NULL)
	{
		free(ptr1);
		return (-1);
	}
	return (0);
}

void	comma_check(char *str)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (str[i])
	{
		if (str[i] == ',')
			commas++;
		i++;
	}
	if (commas > 2)
		error_exit(TOO_MANY_COMMAS);
}

void	vector_valid(double *vec)
{
	int	i;
	int	zeros;

	i = 0;
	zeros = 0;
	while (i < 3)
	{
		if (fabs(vec[i]) > 1)
			error_exit(VEC_INV);
		if (vec[i] > -0.00001 && vec[i] < 0.00001)
			zeros++;
		i++;
	}
	if (zeros == 3)
		error_exit(VEC_INV);
}

void	rgb_check(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			error_exit(RGB_INV);
		i++;
	}
}
