/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 22:10:29 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 18:19:34 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx.h"
#include "minirt.h"
#include "parsing/parsing.h"
#include "rt_error_exit.h"
#include "render/render.h"
#include "translate_data/translate_data.h"

static void	initialize_struct_array(t_stct *structs)
{
	structs->scene = ft_calloc(1, sizeof(t_scene));
	structs->light = ft_calloc(1, sizeof(t_lt));
	if (!structs->scene || !structs->light)
		error_exit(MALLOC_F);
	structs->res_ini = 0;
	structs->amb_ini = 0;
	structs->cam_ini = 0;
	structs->light_ini = 0;
	structs->sphere = 0;
	structs->plane = 0;
	structs->cylinder = 0;
}

static void	free_struct(t_stct *structs)
{
	free(structs->scene);
	free(structs->light);
	if (structs->plane != NULL)
		ft_lstclear(&structs->plane, &free);
	if (structs->sphere != NULL)
		ft_lstclear(&structs->sphere, &free);
	if (structs->cylinder != NULL)
		ft_lstclear(&structs->cylinder, &free);
}

static int	exit_program(void)
{
	error_exit(CLEAN);
	return (0);
}

static int	close_window(int keycode, t_data *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit_program();
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stct		structs;
	t_render	render;
	t_data		mlx;

	if (argc < 2)
		error_exit(NO_FILE);
	initialize_struct_array(&structs);
	arg_parse(argv, &structs);
	translate_data(&structs, &render);
	free_struct(&structs);
	render_world(&mlx, &render);
	free_data(&render);
	mlx_key_hook(mlx.win, close_window, &mlx);
	mlx_hook(mlx.win, 17, 1L, exit_program, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
