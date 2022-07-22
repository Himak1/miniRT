/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_error_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 22:09:08 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 16:09:25 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rt_error_exit.h"

static void	error_codes_part1(int error_code)
{
	if (error_code == MALLOC_F)
		write(1, "ERROR\n- Memory allocation failed\n", 33);
	else if (error_code == NO_FILE)
		write(1, "ERROR\n- No file given as argument\n", 35);
	else if (error_code == BAD_EXTENSION)
		write(1, "ERROR\n- Wrong file extension\n", 30);
	else if (error_code == OPEN_F)
		write(1, "ERROR\n- Failed to open file\n", 29);
	else if (error_code == RES_HIGH)
		write(1, "ERROR\n- Resolution setting is invalid\n", 38);
}

static void	error_codes_part2(int error_code)
{
	if (error_code == VEC_INV)
		write(1, "ERROR\n- Orientation vectors are invalid\n", 40);
	else if (error_code == RGB_INV)
		write(1, "ERROR\n- Invalid RGB settings\n", 29);
	else if (error_code == FOV_INV)
		write(1, "ERROR\n- FOV is invalid. Stay in range of 1 - 180\n", 49);
	else if (error_code == RACL_MULT)
		write(1, "ERROR\n- Multiple occurences of capital element\n", 48);
	else if (error_code == IDEN_INV)
		write(1, "ERROR\n- Invalid element identifier in file\n", 43);
	else if (error_code == MISSING_PARAM)
		write(1, "ERROR\n- Missing parameters for elements\n", 40);
	else if (error_code == NOT_INT)
		write(1, "ERROR\n- Cannot convert characters into an int\n", 46);
	else if (error_code == NOT_DBL)
		write(1, "ERROR\n- Cannot convert characters into a double\n", 48);
	else if (error_code == LIGHT_INV)
		write(1, "ERROR\n- Invalid ambient and/or light ratio\n", 43);
	else if (error_code == SIZE_INV)
		write(1, "ERROR\n- One of your objects has an invalid size\n", 48);
	else if (error_code == TOO_MANY_COMMAS)
		write(1, "ERROR\n- 2 or more commas seperating values\n", 43);
}

void	error_exit(int error_code)
{
	if (error_code >= -5)
		error_codes_part1(error_code);
	else
		error_codes_part2(error_code);
	if (error_code != CLEAN)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
