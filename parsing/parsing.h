/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:32:38 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/27 18:19:25 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../libft/libft.h"
# include "../rt_error_exit.h"

typedef struct s_scene {
	int			x_render;
	int			y_render;
	double		amb_ratio;
	int			amb_rgb[3];
	double		cam_xyz[3];
	double		vec_xyz[3];
	int			cam_fov;
}				t_scene;

typedef struct s_lt {
	double		xyz[3];
	int			rgb[3];
	double		ratio;
}				t_lt;

typedef struct s_pl {
	double		pnt_xyz[3];
	double		vec_xyz[3];
	int			rgb[3];
}				t_pl;

typedef struct s_sp {
	double		xyz[3];
	double		dia;
	int			rgb[3];
}				t_sp;

typedef struct s_cy {
	double		pnt_xyz[3];
	double		vec_xyz[3];
	double		dia;
	double		hei;
	int			rgb[3];
}				t_cy;

typedef struct s_stct {
	t_scene	*scene;
	t_lt	*light;
	t_list	*sphere;
	t_list	*plane;
	t_list	*cylinder;
	int		res_ini;
	int		amb_ini;
	int		cam_ini;
	int		light_ini;
}			t_stct;

double	ft_atof(char *str);

void	arg_parse(char *argv[], t_stct *structs);

double	extract_double(char *value_str);
int		extract_int(char *value_str);
void	tri_int_set(char *values, int int_arr[]);
void	tri_dbl_set(char *values, double *int_arr);
void	rgb_check(int *rgb);
void	vector_valid(double *vec);
void	comma_check(char *str);

int		node_check(void *ptr1, void *ptr2);
int		ptr_arraylen(char **ptr_array);

void	res_set(char *line[], t_stct *structs);
void	amb_set(char *line[], t_stct *structs);
void	cam_set(char *line[], t_stct *structs);
void	light_set(char *line[], t_stct *structs);
void	plane_set(char *line[], t_stct *structs);
void	sphere_set(char *line[], t_stct *structs);
void	cylin_set(char *line[], t_stct *structs);

char	*readfile(char *file_name);

#endif
