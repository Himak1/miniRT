/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_argparse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 13:34:58 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 19:07:26 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "parsing.h"
#include <sys/stat.h>
#include <fcntl.h>

/*
** check_var sends the executable to the correct function to fill in a struct.
** The functions all end in *set() 
*/

#include <string.h>
static void	extension_check(char *file)
{
	int		len;
	char	*rt_present;

	len = ft_strlen(file);
	rt_present = ft_strnstr(file, ".rt", len);
	if (rt_present == NULL)
		error_exit(BAD_EXTENSION);
	else if (rt_present != NULL && len == 3)
		error_exit(BAD_EXTENSION);
	else if (rt_present != NULL && file[len - 1] != 't')
		error_exit(BAD_EXTENSION);
}

static void	jump_to_func(char *line, char **subline, t_stct *structs)
{
	if (!ft_strncmp(line, "pl ", 3))
		plane_set(subline, structs);
	else if (!ft_strncmp(line, "sp ", 3))
		sphere_set(subline, structs);
	else if (!ft_strncmp(line, "cy ", 3))
		cylin_set(subline, structs);
	else if (!ft_strncmp(line, "A ", 2))
		amb_set(subline, structs);
	else if (!ft_strncmp(line, "C ", 2))
		cam_set(subline, structs);
	else if (!ft_strncmp(line, "L ", 2))
		light_set(subline, structs);
	else if (!ft_strncmp(line, "R ", 2))
		res_set(subline, structs);
	else
		error_exit(IDEN_INV);
}

void	line_parse(char *line, t_stct *structs)
{
	char	**subline;

	subline = ft_split(line, ' ');
	if (!subline)
		error_exit(MALLOC_F);
	if (!subline[0])
		error_exit(IDEN_INV);
	jump_to_func(line, subline, structs);
	ft_free_2d((void **)subline);
	free(subline);
}

void	arg_parse(char *argv[], t_stct *structs)
{
	char	*line;
	int		fd;
	int		gnl_ret;

	extension_check(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit(OPEN_F);
	while (1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
			error_exit(MALLOC_F);
		if (strncmp(line, "", 2))
			line_parse(line, structs);
		if (gnl_ret == 0)
			break ;
		free(line);
	}
	free(line);
	close(fd);
}
