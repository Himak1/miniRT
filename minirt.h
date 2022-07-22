/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 22:10:09 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/21 22:10:21 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "libft/libft.h"
# include "rt_error_exit.h"

/*
** The s_scene struct can only occur once in a file
** Other structs can be turned into linked lists.
*/

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_data;

//int		mlx_ini(t_data *mlx);

void	my_pixel_put(t_data *mlx, int x, int y, int color);		
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

char	**ft_seperate(char *line);
#endif
