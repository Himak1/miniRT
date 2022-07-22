/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_values_from_str.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:30:49 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/23 14:19:24 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>

// extract_int() is an ft_atoi() wrapper. 
// It checks whether value_str doesn't contain any
// non-digit characters before running ft_atoi()
// If it does find non-digit characters it calls error_exit()

int	extract_int(char *value_str)
{
	int	i;

	i = 0;
	if (value_str[i] == '-')
		i++;
	if (value_str[i] == '0' && ft_isdigit(value_str[i + 1]))
		error_exit(NOT_INT);
	while (value_str[i])
	{
		if (ft_isdigit(value_str[i]) == 0)
			error_exit(NOT_INT);
		i++;
	}
	return (ft_atoi(value_str));
}

// extract_double is an ft_atof() wrapper.
// It checks for non-digit and '.' characters in value_str.
// If it does find forbidden chars it calls error_exit()

double	extract_double(char *value_str)
{
	int	i;
	int	dot_present;

	i = 0;
	dot_present = 0;
	if (value_str[i] == '-')
		i++;
	if (value_str[i] == '0' && ft_isdigit(value_str[i + 1]))
		error_exit(NOT_DBL);
	while (value_str[i])
	{
		if (value_str[i] == '.')
			dot_present++;
		if (!ft_isdigit(value_str[i]) && dot_present != 1)
			error_exit(NOT_DBL);
		i++;
	}
	return (ft_atof(value_str));
}

void	tri_dbl_set(char *values_str, double *dbl_arr)
{
	char	**str_arr;
	int		i;

	i = 0;
	comma_check(values_str);
	str_arr = ft_split(values_str, ',');
	if (!str_arr)
		error_exit(MALLOC_F);
	while (str_arr[i])
	{
		dbl_arr[i] = extract_double(str_arr[i]);
		i++;
	}
	if (i != 3)
		error_exit(MISSING_PARAM);
	ft_free_2d((void *)str_arr);
	free(str_arr);
}

void	tri_int_set(char *values_str, int *int_arr)
{
	char	**str_arr;
	int		i;

	i = 0;
	comma_check(values_str);
	str_arr = ft_split(values_str, ',');
	if (!str_arr)
		error_exit(MALLOC_F);
	while (str_arr[i])
	{
		int_arr[i] = extract_int(str_arr[i]);
		i++;
	}
	if (i != 3)
		error_exit(MISSING_PARAM);
	ft_free_2d((void *)str_arr);
	free(str_arr);
}
