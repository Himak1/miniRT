/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   epsilon.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:58:19 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 19:58:20 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	equal(double a, double b)
{
	double	result;

	result = a - b;
	if (result < 0.00001 && result > -0.00001)
		return (1);
	else
		return (0);
}
