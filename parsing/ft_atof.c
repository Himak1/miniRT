/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:35:32 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 18:35:33 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static double	divide(double ret, int div_count, int negative)
{
	while (div_count != 0)
	{
		ret /= 10;
		div_count--;
	}
	if (negative == 1)
		return (ret * -1);
	return (ret);
}

static int	divlen(char *str)
{
	char	*dot;

	dot = ft_strchr(str, '.');
	if (dot != NULL)
		dot++;
	else
		return (0);
	return (ft_strlen(dot));
}

double	ft_atof(char *str)
{
	int		i;
	int		div_count;
	int		negative;
	double	ret;

	i = 0;
	ret = 0;
	negative = 0;
	div_count = divlen(str);
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	while (str && (ft_isdigit(str[i]) != 0 || str[i] == '.'))
	{
		if (str[i] != '.')
		{
			ret *= 10;
			ret += str[i] - '0';
		}
		i++;
	}
	return (divide(ret, div_count, negative));
}
